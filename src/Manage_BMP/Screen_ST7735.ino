#include <Arduino.h>

#include "Config.h"

#ifdef ST7735
    #include <Adafruit_GFX.h>
    #include <Adafruit_ST7735.h>
    #include <SPI.h>
    
    #include "TFT_Positions.h"

    #define TFT_CS 10
    #define TFT_RST 8
    #define TFT_DC 9

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

    void screenBoxBase() 
    {
        #ifdef TEMP_SENSOR
            makeBoxWithTitle(BOX_A0_X, BOX_A0_Y, BOX_FROMREF_VALUE_RECT_X, BOX_FROMREF_VALUE_RECT_Y, "T °C");
        #endif

        #ifdef PRESS_SENSOR
            makeBoxWithTitle(BOX_A1_X, BOX_A1_Y, BOX_FROMREF_VALUE_RECT_X, BOX_FROMREF_VALUE_RECT_Y, " hP");
        #endif
    }

    void setupOutput(void)
    {
        tft.initR(INITR_BLACKTAB);
        screenSetup();

        delay(1000);
        screenBoxBase();
    }

    void loopOutput(void) {
        #ifdef TEMP_SENSOR
            setFloatValueInBox(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, sensorsValues.Temperature, 2);
        #endif

        #ifdef PRESS_SENSOR
            setFloatValueInBox(BOX_A1_X, BOX_A1_Y, BOX_GENERIC_W, BOX_GENERIC_H, sensorsValues.Pressure, 0);
        #endif
    }
#endif