#include <Arduino.h>

#include "Config.h"

#ifdef DUMMY_TEMP
float readTemp()
{   
    sensorsValues.Temperature = 0.0F
    return sensorsValues.Temperature;
}
#endif