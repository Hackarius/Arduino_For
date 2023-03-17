#include "Config.h"

#ifdef SENSOR_BMP180
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
    float readPressure(void)
    {
        sensorsValues.Pressure = bmp.readPressure() / 100.0F;
        return sensorsValues.Pressure;
    }

    /**
     * @def Read temp by sensor
     * @param void
     * @return float
    */
    #ifdef SENSOR_BMP180_TEMP
    float readTemp(void)
    {
        sensorsValues.Temperature =  bmp.readTemperature();
        return sensorsValues.Temperature;
    }
    #endif
#endif