#ifndef _CONFIG_ADVANCE_H_
    #define _CONFIG_ADVANCE_H_

    // Define module for temperature
    #if defined(BMP_180_TEMP) && !defined(BMP_180)
        #undef BMP_180_TEMP
        #define DUMMY_TEMP
    #endif

    #if defined(BMP_180_TEMP) || defined(DUMMY_TEMP)
        #define TEMP_SENSOR
    #endif

    // Define module for pressure
    #if defined(BMP_180_PRESS) && !defined(BMP_180)
        #undef BMP_180_PRESS
        #define DUMMY_PRESS
    #endif

    #if defined(BMP_180_PRESS) || defined(DUMMY_PRESS)
        #define PRESS_SENSOR
    #endif

    // Define module for RTC
    #if defined(DS_1307_RTC) && !defined(RTC_MOD)
        #undef DS_1307_RTC
        #define DUMMY_RTC
    #endif

    #if defined(DS_1307_RTC) || defined(DUMMY_RTC)
        #define RTC_SENSOR
    #endif

    // Define module for screen
    #if defined(ST7735) && !defined(SCREEN)
        #undef ST7735
        #define DUMMY_SCREEN
    #endif

    #if defined(ST7735) || defined(DUMMY_SCREEN)
        #define SCREEN_MODULE
    #endif
#endif