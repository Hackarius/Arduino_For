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
        #ifdef HUMIDITY_SENSOR
            readHumidity();
            char buffer[5];
            sprintf(buffer, "%f", sensorsValues.Humidity);
            writeFile("sensor.log", buffer);
        #endif

        #ifdef RTC_SENSOR
            // Serial.println(sensorsValues.);
        #endif
        
        readFile("sensor.log");
    #endif

    delay(WAITING);
}