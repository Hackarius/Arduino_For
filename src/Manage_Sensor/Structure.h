#ifndef _STRUCTURE_H_
    #define _STRUCTURE_H_
    #include "Config.h"

    struct SensorsValues {
        #ifdef PRESS_SENSOR
            uint16_t    Pressure;
        #endif
        
        #ifdef TEMP_SENSOR
            float       Temperature;
        #endif

        #ifdef HUMIDITY_SENSOR
            uint8_t       Humidity;
        #endif
    };
#endif