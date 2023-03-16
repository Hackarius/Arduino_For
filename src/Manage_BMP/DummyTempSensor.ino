#include "Config.h"

#ifdef DUMMY_TEMP
/**
 * @def Read fake temp
 * @param void
 * @return float Return 0.0F as fake value
*/
float readTemp(void)
{   
    sensorsValues.Temperature = 0.0F
    return sensorsValues.Temperature;
}
#endif