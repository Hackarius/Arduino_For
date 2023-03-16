#include <Arduino.h>
#include <DS1307RTC.h>
#include <TimeLib.h>
#include "DS1307.h"

void readAndDisplayHourTime() {
    tmElements_t tm;

    if (RTC.read(tm)) {
        
    }

    delay(1000);
}