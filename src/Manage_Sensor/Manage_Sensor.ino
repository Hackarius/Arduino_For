#include <TimeLib.h>
#include <DHT.h>

#include "Config.h"
#include "Structure.h"

#define WAITING 1000
struct SensorsValues sensorsValues;

void setup(void)
{
    Serial.begin(9600);

    #ifdef SCREEN_MODULE
        setupOutput();
    #endif

    #ifdef HUMIDITY_SENSOR
        setupHumidity();
    #endif

    #ifdef TEMP_SENSOR
        setupTemp();
    #endif

    #ifdef PRESS_SENSOR
        setupPressure();
    #endif

    #ifdef SDCARD_MODULE
        setupCardReader();
        clearFile("sensor.log");
    #endif

    delay(WAITING);
}

void loop()
{
    #ifdef SCREEN_MODULE
        loopOutput();
    #endif

    #ifdef SDCARD_MODULE
        #ifdef RTC_SENSOR
            // Serial.println(getDateTime());
        #endif

        #ifdef HUMIDITY_SENSOR
            readHumidity();

            char buffer[10];
            sprintf(buffer, "%d", sensorsValues.Humidity);
            writeFile("sensor.log", buffer);
        #endif
        
        readFile("sensor.log");
    #endif

    delay(WAITING);
}