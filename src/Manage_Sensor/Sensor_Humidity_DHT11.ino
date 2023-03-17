#include "Config.h"

#ifdef SENSOR_DHT11
    #include <DHT.h>

    #include "Structure.h"

    #define DHTPIN 3
    #define DHTTYPE DHT11

    DHT dht(DHTPIN, DHTTYPE);

    /**
     * @def Initialize DHT sensor
     * @param void
     * @return void
    */ 
    void setupHumidity(void) 
    {
        dht.begin();
    }

    /**
     * @def Function specified to read humidity in the area
    */
    float readHumidity(void) 
    {
        sensorsValues.Humidity = dht.readHumidity();

        if (isnan(sensorsValues.Humidity)) {
            sensorsValues.Humidity = 0.0F;
        }

        return sensorsValues.Humidity;
    }

    /**
     * @def Read temperature in celcius
     * @param void
     * @return float
    */
    #ifdef SENSOR_DHT11_TEMP
    float readTemp(void)
    {
        sensorsValues.Temperature = dht.readTemperature();

        if (isnan(sensorsValues.Temperature)) {
            sensorsValues.Temperature = 0.0F;
        }

        return sensorsValues.Temperature;
    }
    #endif

    /**
     * @def Read temperature in Fahrenheit
     * @param void
     * @return float
    */
    #ifdef SENSOR_DHT11_TEMP
    float readTempFahrenheit(void)
    {
        sensorsValues.Temperature = dht.readTemperature(true);

        if (isnan(sensorsValues.Temperature)) {
            sensorsValues.Temperature = 0.0F;
        }

        return sensorsValues.Temperature;
    }
    #endif
#endif