#include <DS1307RTC.h>
#include <TimeLib.h>

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