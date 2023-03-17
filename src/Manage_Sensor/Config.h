#ifndef _CONFIG_H_
#define _CONFIG_H_
    /**
     * Sensor of Pressure
    */
    #define SENSOR_BMP180

    /**
     * Sensor of Humidity
    */
    #define SENSOR_DHT11

    /**
     * Sensor of Temperature
    */
    // #define SENSOR_BMP180_TEMP
    #define SENSOR_DS18B20
    // #define SENSOR_DHT11_TEMP

    /**
     * Sensor for RTC
    */
    #define SENSOR_DS1307

    /**
     * SD Card reader
    */
    #define MODULE_MSDCARD_READER
    
    /**
     * Screen
    */
    // #define SCREEN_ST77XX
    // #define SCREEN_ST7735
    // #define LCD_2X16

    /**
     * Sensor DUMMY
    */ 
    // #define DUMMY_TEMP
    // #define DUMMY_PRESS
    // #define DUMMY_HUMIDITY
    // #define DUMMY_RTC
    // #define DUMMY_SDCARD
    // #define DUMMY_SCREEN
    
    #include "Config_Checker.h"
#endif