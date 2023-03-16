#include "Config.h"

#ifdef DS18B20
    #include <OneWire.h>
    #include <DallasTemperature.h>

    #define ONE_WIRE_BUS 2

    OneWire oneWire(ONE_WIRE_BUS);
    DallasTemperature sensors(&oneWire);

    /**
     * @def Setupt temp sensor
     * @param void
     * @return void
    */
    void setupTempSensor(void) {
        sensors.begin();
    }

    /**
     * @def Read temp by the sensors DS18B20
     * @param void
     * @return float
    */
    #ifdef DS18B20_TEMP
    float readTemp(void) {
        sensors.requestTemperatures();

        sensorsValues.Temperature = sensors.getTempCByIndex(0);
        return sensorsValues.Temperature;
    }
    #endif
#endif