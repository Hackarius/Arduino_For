#include <Arduino.h>
#include <DS1307RTC.h>
#include <TimeLib.h>
#include "DS1307.h"
#include "tft_visual_frame_framework.h"

/**
 * @def display hour time on screen
 * @param void
 * @return void
*/
void readAndDisplayHourTime(void) {
    tmElements_t tm;

    if (RTC.read(tm)) {
        makeBandWithHour(tm);
    } else  {
        Serial.print("ERROR DS1307, not initialized !");
    }

    delay(1000);
}