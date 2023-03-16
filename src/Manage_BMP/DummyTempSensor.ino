#include <Arduino.h>

#include "Config.h"

#ifdef DUMMY_TEMP
float readTemp()
{
    return 0.0F;
}
#endif