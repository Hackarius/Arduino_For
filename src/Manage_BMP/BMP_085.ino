#include <Arduino.h>
#include <Adafruit_BMP085.h>

#include "BMP_085.h"
#include "TFT_Framework.h"
#include "Config.h"

#ifdef BMP_180
    bool setupPressure(void)
    {
        return bmp.begin();
    }

    float readPressure(void)
    {
        float psrHP = 0.0F;
        psrHP = bmp.readPressure() / 100.0F;
        return psrHP;
    }

    #ifdef BMP_180_TEMP
    float readTemp(void)
    {
        float t0 = 0.0F;
        t0 =  bmp.readTemperature();
        return t0;
    }
    #endif
#endif