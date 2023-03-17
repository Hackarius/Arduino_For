#include "Config.h"

#ifdef SCREEN_ST77XX
    #include "Adafruit_ST77xx.h"

    #ifndef _TFT_POSITIONS_H_
        #define _TFT_POSITIONS_H_

        /**
         * Define new color
        */
        #define ST77XX_PINK   0xEAEB
        #define ST77XX_BLLM   0x7FB8

        /**
         * Define default size of TFT 1.8 screen
        */
        #define TFT_WIDTH   128.0F
        #define TFT_HEIGHT  160.0F
        #define TFT_BACKGROUND_COLOR ST77XX_BLACK

        #define NORMAL_CHAR_SIZE 8

        /**
         * Define position about box for function makeBox
        */
        #define BOX_FROMREF_TITLE_X             2
        #define BOX_FROMREF_TITLE_Y             6
        #define BOX_FROMREF_VALUE_RECT_X        2
        #define BOX_FROMREF_VALUE_RECT_Y        20
        #define BOX_FROMREF_VALUE_X             (BOX_FROMREF_VALUE_RECT_X + 2)
        #define BOX_FROMREF_VALUE_Y             (BOX_FROMREF_VALUE_RECT_Y + (BOX_VALUE_SIZE * NORMAL_CHAR_SIZE))
        #define SMALLBOX_FROMREF_VALUE_X        (BOX_FROMREF_VALUE_RECT_X + 2)
        #define SMALLBOX_FROMREF_VALUE_Y        (BOX_FROMREF_VALUE_RECT_Y + 2)
        #define BOX_TITLE_SIZE                  1
        #define BOX_TITLE_COLOR                 ST77XX_WHITE
        #define BOX_VALUE_SIZE                  2
        #define BOX_VALUE_COLOR                 ST77XX_BLACK

        /**
         * Define generic dimensions
        */
        #define BOX_GENERIC_W           (TFT_WIDTH / 2.0F)
        #define BOX_GENERIC_H           ((TFT_HEIGHT - 25.0F) / 2.0F)

        #define SMALLBOX_GENERIC_W      (TFT_WIDTH / 2.0F)
        #define SMALLBOX_GENERIC_H      ((TFT_HEIGHT - 25.0F) / 3.0F)
        
        #define BOX_GENERIC_VALUE_PREC  2

        /**
         * Define first A0 box parameter on line one
        */
        #define BOX_A0_X    0
        #define BOX_A0_Y    40

        /**
         * Define second A1 box parameter on line one
        */
        #define BOX_A1_X    BOX_GENERIC_W
        #define BOX_A1_Y    40

        /**
         * Define first B2 box parameter on line two
        */
        #define BOX_B0_X    0
        #define BOX_B0_Y    80
    #endif
#endif