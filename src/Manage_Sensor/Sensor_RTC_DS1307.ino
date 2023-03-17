#include "Config.h"

#ifdef SENSOR_DS1307
    #include <DS1307RTC.h>
    #include <TimeLib.h>

    /**
     * @def display hour time on screen
     * @param void
     * @return void
    */
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