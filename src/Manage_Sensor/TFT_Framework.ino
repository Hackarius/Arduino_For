#include "Config.h"

#ifdef SCREEN_ST77XX
    #include <Adafruit_ST77XX.h>
    #include <TimeLib.h>

    #include "TFT_Positions.h"

    void setFloatValueInBox(uint8_t, uint8_t, uint8_t, uint8_t, float, uint8_t);

    /**
     * @def Insert text at position
     * @param uint8_t (x) position in x on width
     * @param uint8_t (y) position in y on height
     * @param char (*t) title of the box
     * @param uint16_t (c) color of the text
     * @param uint8_t (s) size for the text
     * @return void
     */
    void setText(uint8_t x, uint8_t y, const char *t, uint16_t c, uint8_t s) 
    {
        tft.setCursor(x, y);
        tft.setTextColor(c);
        tft.setTextWrap(true);
        tft.setTextSize(s);
        tft.print(t);
    }

    /**
     * @def Create box and insert a title
     * @param uint8_t (x) position in x on width
     * @param uint8_t (y) position in y on height
     * @param uint8_t (w) size of width
     * @param uint8_t (h) size of height
     * @param char (*t) title of the box
     * @return void
     */
    void makeBoxWithTitle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *t) 
    {
        setText(x + BOX_FROMREF_TITLE_X, y + BOX_FROMREF_TITLE_Y, t, BOX_TITLE_COLOR, BOX_TITLE_SIZE);
        makeBox(x, y, w, h);
        setFloatValueInBox(x, y, w, h, 0.0F, 2);
    }

    /**
     * @def Create simple box
     * @param uint8_t (x) position in x on width
     * @param uint8_t (y) position in y on height
     * @param uint8_t (w) size of width
     * @param uint8_t (h) size of height
     * @return void
     */
    void makeBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h) 
    {
        tft.fillRect(
            x + BOX_FROMREF_VALUE_RECT_X,
            y + BOX_FROMREF_VALUE_RECT_Y,
            w - BOX_FROMREF_VALUE_RECT_X * 2,
            h - BOX_FROMREF_VALUE_RECT_Y - 2,
            BOX_TITLE_COLOR);
    }

    /**
     * @def Position correctly float value inside the box newly created
     * @param uint8_t (x) position in x on width
     * @param uint8_t (y) position in y on height
     * @param uint8_t (w) size of width
     * @param uint8_t (h) size of height
     * @param float (v) value in float to write
     * @param uint8_t (p) precision after comma sign
     * @return void
     */
    void setFloatValueInBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float v, uint8_t p) 
    {
        char buffer[p + 4];
        makeBox(x, y, w, h);
        setText(x + SMALLBOX_FROMREF_VALUE_X, y + SMALLBOX_FROMREF_VALUE_Y, dtostrf(v, 2, p, buffer), BOX_VALUE_COLOR, BOX_VALUE_SIZE);
    }

    /**
     * @def Create band on top of the screen
     * @param void
     * @return void
     */
    void makeBand(void) 
    {
        tft.fillRect(0, 0, tft.width(), 10, ST77XX_BLLM);
        tft.fillRect(tft.width() / 2 - 31, 0, 62, 16, ST77XX_BLLM);
    }

    /**
     * @def Function to write hour in specific case on display
     * @param tmElements_t (tm) time struct object
     * @return void
     */
    void makeBandWithDate(tmElements_t tm) 
    {
        makeBand();
        char buffer[11];

        tft.setCursor(2, 1);
        tft.setTextSize(1);
        tft.setTextColor(ST77XX_BLACK);

        sprintf(buffer, "%02d/%02d", tm.Day, tm.Month);
        tft.print(buffer);
        tft.setCursor(100, 1);
        tft.print(tmYearToCalendar(tm.Year));

        tft.setCursor(tft.width() / 2 - 30, 1);
        tft.setTextSize(2);
        sprintf(buffer, "%02d:%02d", tm.Hour, tm.Minute);
        tft.print(buffer);
    }
#endif
    