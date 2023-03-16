#include "Config.h"

#ifdef BMP_180
    #include <Adafruit_BMP085.h>
    
    #include "Structure.h"

    Adafruit_BMP085 bmp;

    /**
     * @def Setup sensor for pressure
     * @param void
     * @return bool
    */
    bool setupPressure(void)
    {
        return bmp.begin();
    }

    /**
     * @def Read pressure by sensor
     * @param void
     * @return float
    */
    #ifdef BMP_180_PRESS
    float readPressure(void)
    {
        sensorsValues.Pressure = bmp.readPressure() / 100.0F;
        return sensorsValues.Pressure;
    }
    #endif

    /**
     * @def Read temp by sensor
     * @param void
     * @return float
    */
    #ifdef BMP_180_TEMP
    float readTemp(void)
    {
        sensorsValues.Temperature =  bmp.readTemperature();
        return sensorsValues.Temperature;
    }
    #endif
#endif