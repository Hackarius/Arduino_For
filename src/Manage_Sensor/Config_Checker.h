#ifndef _CONFIG_ADVANCE_H_
    #define _CONFIG_ADVANCE_H_

    /**
     * Checker
    */
    // Verify BMP180 module exist to read temperature
    #if defined(SENSOR_BMP180_TEMP) && !defined(SENSOR_BMP180)
        #undef SENSOR_BMP180_TEMP
        #define DUMMY_TEMP
    #endif

    #if defined(SENSOR_DHT11_TEMP) && !defined(SENSOR_DHT11)
        #undef SENSOR_DHT11_TEMP
        #define DUMMY_TEMP
    #endif

    #if defined(SCREEN_ST7735) && !defined(SCREEN_ST77XX)
        #undef SCREEN_ST7735
        #define DUMMY_SCREEN
    #endif

    /**
     * Check, is okay to use if module is defined
    */
    // Define sensor for Temperature
    #if defined(SENSOR_BMP180_TEMP) || defined(DUMMY_TEMP) || defined(SENSOR_DS18B20) || defined(SENSOR_DHT11_TEMP)
        #define TEMP_SENSOR
    #endif

    // Define sensor for Pressure
    #if defined(SENSOR_BMP180) || defined(DUMMY_PRESS)
        #define PRESS_SENSOR
    #endif

    // Defined sensor for Humidity
    #if defined(SENSOR_DHT11) || defined (DUMMY_HUMIDITY)
        #define HUMIDITY_SENSOR
    #endif

    // Define module for RTC
    #if defined(SENSOR_DS1307) || defined(DUMMY_RTC)
        #define RTC_SENSOR
    #endif

    #if defined(MODULE_MSDCARD_READER) || defined(DUMMY_SDCARD)
        #define SDCARD_MODULE
    #endif

    // Define module for screen
    #if defined(SCREEN_ST7735) || defined(DUMMY_SCREEN)
        #define SCREEN_MODULE
    #endif
#endif