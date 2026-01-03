/**
 * @file SmoothValue. h
 * @brief Klasa do wygładzania wartości sensorów (EMA - Exponential Moving Average)
 * @version 2.0 - Support for 16-bit sensor IDs
 *
 * Zapewnia płynne przejścia między wartościami poprzez interpolację
 */

#ifndef SMOOTH_VALUE_H
#define SMOOTH_VALUE_H

#include <Arduino.h>

// Invalid sensor ID marker (16-bit)
#define SENSOR_ID_INVALID 0xFFFF

/**
 * @brief Pojedyncza wygładzona wartość
 */
class SmoothValue
{
public:
    SmoothValue(float smoothing = 0.15f)
        : m_current(0.0f), m_target(0.0f), m_smoothing(smoothing), m_initialized(false)
    {
    }

    /**
     * @brief Ustaw nową wartość docelową
     */
    void setTarget(float value)
    {
        if (!m_initialized)
        {
            m_current = value;
            m_initialized = true;
        }
        m_target = value;
    }

    /**
     * @brief Aktualizuj wartość bieżącą (interpolacja w kierunku celu)
     * @return Aktualna wygładzona wartość
     */
    float update()
    {
        if (!m_initialized)
            return 0.0f;
        m_current += (m_target - m_current) * m_smoothing;
        return m_current;
    }

    /**
     * @brief Pobierz aktualną wygładzoną wartość bez aktualizacji
     */
    float get() const { return m_current; }

    /**
     * @brief Pobierz wartość docelową
     */
    float getTarget() const { return m_target; }

    /**
     * @brief Zmień współczynnik wygładzania
     * @param smoothing Wartość 0.0-1.0 (mniejsza = wolniejsze przejścia)
     */
    void setSmoothing(float smoothing)
    {
        m_smoothing = constrain(smoothing, 0.01f, 1.0f);
    }

    /**
     * @brief Reset do stanu początkowego
     */
    void reset()
    {
        m_current = 0.0f;
        m_target = 0.0f;
        m_initialized = false;
    }

    /**
     * @brief Natychmiast ustaw wartość (bez interpolacji)
     */
    void setImmediate(float value)
    {
        m_current = value;
        m_target = value;
        m_initialized = true;
    }

    /**
     * @brief Sprawdź czy wartość została zainicjalizowana
     */
    bool isInitialized() const { return m_initialized; }

    /**
     * @brief Sprawdź czy wartość osiągnęła cel (z tolerancją)
     */
    bool isAtTarget(float tolerance = 0.1f) const
    {
        return m_initialized && abs(m_current - m_target) < tolerance;
    }

private:
    float m_current;
    float m_target;
    float m_smoothing;
    bool m_initialized;
};

/**
 * @brief Manager wygładzonych wartości dla wielu sensorów
 * @tparam MAX_SENSORS Maksymalna liczba śledzonych sensorów (domyślnie 64)
 *
 * Obsługuje 16-bitowe ID sensorów (Protocol v2)
 */
template <size_t MAX_SENSORS = 64>
class SmoothValueManager
{
public:
    SmoothValueManager(float defaultSmoothing = 0.15f)
        : m_defaultSmoothing(defaultSmoothing), m_count(0)
    {
        for (size_t i = 0; i < MAX_SENSORS; i++)
        {
            m_ids[i] = SENSOR_ID_INVALID; // 16-bit invalid marker
        }
    }

    /**
     * @brief Ustaw wartość docelową dla sensora
     * @param sensorId 16-bit sensor ID
     * @param value Wartość docelowa
     */
    void setTarget(uint16_t sensorId, float value)
    {
        int idx = findOrCreate(sensorId);
        if (idx >= 0)
        {
            m_values[idx].setTarget(value);
        }
    }

    /**
     * @brief Aktualizuj wszystkie wartości (interpolacja)
     */
    void updateAll()
    {
        for (size_t i = 0; i < m_count; i++)
        {
            m_values[i].update();
        }
    }

    /**
     * @brief Pobierz wygładzoną wartość dla sensora
     * @param sensorId 16-bit sensor ID
     * @param defaultValue Wartość domyślna jeśli sensor nie istnieje
     */
    float get(uint16_t sensorId, float defaultValue = 0.0f) const
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            return m_values[idx].get();
        }
        return defaultValue;
    }

    /**
     * @brief Pobierz wartość docelową dla sensora
     * @param sensorId 16-bit sensor ID
     * @param defaultValue Wartość domyślna jeśli sensor nie istnieje
     */
    float getTarget(uint16_t sensorId, float defaultValue = 0.0f) const
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            return m_values[idx].getTarget();
        }
        return defaultValue;
    }

    /**
     * @brief Pobierz wygładzoną wartość jako int
     * @param sensorId 16-bit sensor ID
     * @param defaultValue Wartość domyślna jeśli sensor nie istnieje
     */
    int getInt(uint16_t sensorId, int defaultValue = 0) const
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            return static_cast<int>(round(m_values[idx].get()));
        }
        return defaultValue;
    }

    /**
     * @brief Pobierz wygładzoną wartość jako int z zaokrągleniem
     * @param sensorId 16-bit sensor ID
     * @param defaultValue Wartość domyślna jeśli sensor nie istnieje
     */
    int getIntRounded(uint16_t sensorId, int defaultValue = 0) const
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            return static_cast<int>(m_values[idx].get() + 0.5f);
        }
        return defaultValue;
    }

    /**
     * @brief Zmień współczynnik wygładzania dla sensora
     * @param sensorId 16-bit sensor ID
     * @param smoothing Wartość 0.0-1.0
     */
    void setSmoothing(uint16_t sensorId, float smoothing)
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            m_values[idx].setSmoothing(smoothing);
        }
    }

    /**
     * @brief Zmień współczynnik wygładzania dla wszystkich sensorów
     * @param smoothing Wartość 0.0-1.0
     */
    void setSmoothingAll(float smoothing)
    {
        m_defaultSmoothing = constrain(smoothing, 0.01f, 1.0f);
        for (size_t i = 0; i < m_count; i++)
        {
            m_values[i].setSmoothing(m_defaultSmoothing);
        }
    }

    /**
     * @brief Zmień domyślny współczynnik wygładzania
     */
    void setDefaultSmoothing(float smoothing)
    {
        m_defaultSmoothing = constrain(smoothing, 0.01f, 1.0f);
    }

    /**
     * @brief Sprawdź czy sensor istnieje w managerze
     * @param sensorId 16-bit sensor ID
     */
    bool exists(uint16_t sensorId) const
    {
        return find(sensorId) >= 0;
    }

    /**
     * @brief Sprawdź czy sensor ma zainicjalizowaną wartość
     * @param sensorId 16-bit sensor ID
     */
    bool isInitialized(uint16_t sensorId) const
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            return m_values[idx].isInitialized();
        }
        return false;
    }

    /**
     * @brief Pobierz liczbę śledzonych sensorów
     */
    size_t count() const { return m_count; }

    /**
     * @brief Pobierz maksymalną liczbę sensorów
     */
    size_t maxCount() const { return MAX_SENSORS; }

    /**
     * @brief Pobierz ID sensora po indeksie
     * @param index Indeks sensora (0 do count()-1)
     * @return ID sensora lub SENSOR_ID_INVALID jeśli indeks nieprawidłowy
     */
    uint16_t getIdByIndex(size_t index) const
    {
        if (index < m_count)
        {
            return m_ids[index];
        }
        return SENSOR_ID_INVALID;
    }

    /**
     * @brief Pobierz wartość sensora po indeksie
     * @param index Indeks sensora (0 do count()-1)
     * @param defaultValue Wartość domyślna jeśli indeks nieprawidłowy
     */
    float getByIndex(size_t index, float defaultValue = 0.0f) const
    {
        if (index < m_count)
        {
            return m_values[index].get();
        }
        return defaultValue;
    }

    /**
     * @brief Natychmiast ustaw wartość (bez interpolacji)
     * @param sensorId 16-bit sensor ID
     * @param value Wartość
     */
    void setImmediate(uint16_t sensorId, float value)
    {
        int idx = findOrCreate(sensorId);
        if (idx >= 0)
        {
            m_values[idx].setImmediate(value);
        }
    }

    /**
     * @brief Usuń sensor z managera
     * @param sensorId 16-bit sensor ID
     * @return true jeśli sensor został usunięty
     */
    bool remove(uint16_t sensorId)
    {
        int idx = find(sensorId);
        if (idx >= 0)
        {
            // Przesuń pozostałe elementy
            for (size_t i = idx; i < m_count - 1; i++)
            {
                m_ids[i] = m_ids[i + 1];
                m_values[i] = m_values[i + 1];
            }
            m_count--;
            m_ids[m_count] = SENSOR_ID_INVALID;
            m_values[m_count].reset();
            return true;
        }
        return false;
    }

    /**
     * @brief Reset wszystkich wartości
     */
    void reset()
    {
        for (size_t i = 0; i < m_count; i++)
        {
            m_values[i].reset();
            m_ids[i] = SENSOR_ID_INVALID;
        }
        m_count = 0;
    }

    /**
     * @brief Wydrukuj debug info do Serial
     */
    void debugPrint() const
    {
        Serial.printf("[SmoothManager] Count: %d/%d\n", m_count, MAX_SENSORS);
        for (size_t i = 0; i < m_count; i++)
        {
            Serial.printf("  [0x%04X] current=%.1f target=%.1f\n",
                          m_ids[i], m_values[i].get(), m_values[i].getTarget());
        }
    }

private:
    /**
     * @brief Znajdź indeks sensora po ID
     * @param sensorId 16-bit sensor ID
     * @return Indeks sensora lub -1 jeśli nie znaleziono
     */
    int find(uint16_t sensorId) const
    {
        for (size_t i = 0; i < m_count; i++)
        {
            if (m_ids[i] == sensorId)
                return static_cast<int>(i);
        }
        return -1;
    }

    /**
     * @brief Znajdź lub utwórz slot dla sensora
     * @param sensorId 16-bit sensor ID
     * @return Indeks sensora lub -1 jeśli brak miejsca
     */
    int findOrCreate(uint16_t sensorId)
    {
        int idx = find(sensorId);
        if (idx >= 0)
            return idx;

        if (m_count < MAX_SENSORS)
        {
            m_ids[m_count] = sensorId;
            m_values[m_count] = SmoothValue(m_defaultSmoothing);
            return static_cast<int>(m_count++);
        }
        return -1;
    }

    SmoothValue m_values[MAX_SENSORS];
    uint16_t m_ids[MAX_SENSORS]; // 16-bit sensor IDs
    float m_defaultSmoothing;
    size_t m_count;
};

#endif // SMOOTH_VALUE_H