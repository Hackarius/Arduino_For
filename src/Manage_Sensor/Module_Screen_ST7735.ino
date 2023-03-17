#include "Config.h"

#ifdef SCREEN_ST7735
    #include <Adafruit_GFX.h>
    #include <Adafruit_ST7735.h>
    #include <SPI.h>
    
    #include "TFT_Positions.h"

    #define TFT_CS 10
    #define TFT_DC 9
    #define TFT_RST 8

    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

    /**
     * @def Setup the screen TFT
     * @param void
     * @return void
     */
    void screenSetup(void) 
    {
        tft.fillScreen(0x0);
        tft.setCursor(34, 20);
        tft.setTextSize(2);
        tft.setTextColor(ST77XX_BLLM);
        tft.print("Orsys");
        tft.setCursor(5, 50);
        tft.setTextSize(1);
        tft.setTextColor(ST77XX_BLLM);
        tft.setCursor(15, 135);
        tft.print("Copyright 2023");
        tft.setCursor(50, 150);
        tft.print("Rev 0.2");
    }

    /**
     * @def Add 2 box with value on screen
     * @param void
     * @return void
    */
    void screenBoxBase(void) 
    {
        #ifdef TEMP_SENSOR
            makeBoxWithTitle(BOX_A0_X, BOX_A0_Y, BOX_FROMREF_VALUE_RECT_X, BOX_FROMREF_VALUE_RECT_Y, "T °C");
        #endif

        #ifdef HUMIDITY_SENSOR
            makeBoxWithTitle(BOX_A0_X, BOX_A0_Y, BOX_FROMREF_VALUE_RECT_X, BOX_FROMREF_VALUE_RECT_Y, "Humidity");
        #endif

        #ifdef PRESS_SENSOR
            makeBoxWithTitle(BOX_A1_X, BOX_A1_Y, BOX_FROMREF_VALUE_RECT_X, BOX_FROMREF_VALUE_RECT_Y, "Pressure");
        #endif
    }

    /**
     * @def Initialize output on screen
     * @param void
     * @return void
    */
    void setupOutput(void) 
    {
        tft.initR(INITR_BLACKTAB);
        screenSetup();

        delay(1000);
        screenBoxBase();

        #ifdef RTC_SENSOR
            readAndDisplayDateTime();
        #endif

        #ifdef HUMIDITY_SENSOR
            setupHumidity();
        #endif

        #ifdef TEMP_SENSOR
            setupTemp();
        #endif

        #ifdef PRESS_SENSOR
            setupPressure();
        #endif
    }

    /**
     * @def Display on screen into newly box created value of sensors
     * @param void
     * @return void
    */
    void loopOutput(void) 
    {
        #ifdef RTC_SENSOR
            readAndDisplayDateTime();
        #endif

        #ifdef TEMP_SENSOR
            readTemp();
            setFloatValueInBox(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, sensorsValues.Temperature, 2);
        #endif

        #ifdef HUMIDITY_SENSOR
            readHumidity();
            setFloatValueInBox(BOX_A0_X, BOX_A0_Y, SMALLBOX_GENERIC_W, SMALLBOX_GENERIC_H, sensorsValues.Humidity, 0);
        #endif

        #ifdef PRESS_SENSOR
            readPressure();
            setFloatValueInBox(BOX_A1_X, BOX_A1_Y, SMALLBOX_GENERIC_W, SMALLBOX_GENERIC_H, sensorsValues.Pressure, 0);
        #endif
    }
#endif