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
    #endif

    delay(WAITING);
}

void loop()
{
    #ifdef SCREEN_MODULE
        loopOutput();
    #endif

    delay(WAITING);
}