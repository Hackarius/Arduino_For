#include "Config.h"

#ifdef SENSOR_DS1307
    #include <DS1307RTC.h>
    #include <TimeLib.h>

    /**
     * @def Get DateTime for logging
     * @param void
     * @return char*
    */
    char* getDateTime(void)
    {
        tmElements_t tm;

        if (RTC.read(tm)) {
            char buffer[50];
            sprintf(buffer, "%04d%02d%02d - %02d:%02d", tmYearToCalendar(tm.Year), tm.Month, tm.Day, tm.Hour, tm.Minute);
            return buffer;
        } else  {
            Serial.print("ERROR DS1307, not initialized !");
            return;
        }
    }

    /**
     * @def display hour time on screen
     * @param void
     * @return void
    */
    #ifdef SCREEN_ST77XX
    void readAndDisplayDateTime(void) 
    {
        tmElements_t tm;

        if (RTC.read(tm)) {
            makeBandWithDate(tm);
        } else  {
            Serial.print("ERROR DS1307, not initialized !");
        }
    }
    #endif
#endif