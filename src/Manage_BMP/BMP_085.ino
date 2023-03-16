#include <Arduino.h>
#include <Adafruit_BMP085.h>

#include "Config.h"

#ifdef BMP_180
    #include "Structure.h"
    Adafruit_BMP085 bmp;

    bool setupPressure(void)
    {
        return bmp.begin();
    }

    float readPressure(void)
    {
        sensorsValues.Pressure = bmp.readPressure() / 100.0F;
        return sensorsValues.Pressure;
    }

    #ifdef BMP_180_TEMP
    float readTemp(void)
    {
        sensorsValues.Temperature =  bmp.readTemperature();
        return sensorsValues.Temperature;
    }
    #endif
#endif