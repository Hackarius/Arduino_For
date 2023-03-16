#include <Arduino.h>
#include <Adafruit_ST77XX.h>
#include "tft_visual_frame_framework.h"
#include "tft_positions.h"

void setFloatValueInBox(uint8_t, uint8_t, uint8_t, uint8_t, float, uint8_t);

/**
 * @def create box and insert a title
 *
 * @param x position in x on width
 * @param y position in y on height
 * @param w size of width
 * @param h size of height
 * @param t title of the box
 */
void makeBoxWithTitle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *t)
{
    tft.setCursor(x + BOX_FROMREF_TITLE_X, y + BOX_FROMREF_TITLE_Y);
    tft.setTextColor(BOX_TITLE_COLOR);
    tft.setTextWrap(true);
    tft.setTextSize(BOX_TITLE_SIZE);
    tft.print(t);

    makeBox(x, y, w, h);
    setFloatValueInBox(x, y, w, h, 0.0F, 2);
}

/**
 * @def create box
 *
 * @param x position in x on width
 * @param y position in y on height
 * @param w size of width
 * @param h size of height
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
 *
 * @param x position in x on width
 * @param y position in y on height
 * @param w size of width
 * @param h size of height
 * @param v value in float to write
 * @param p precision after comma sign
 */
void setFloatValueInBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float v, uint8_t p)
{
    char buffer[p + 4];

    tft.fillRect(x + BOX_FROMREF_VALUE_RECT_X,
                 y + BOX_FROMREF_VALUE_RECT_Y,
                 w - BOX_FROMREF_VALUE_RECT_X * 2,
                 h - BOX_FROMREF_VALUE_RECT_Y - 2,
                 BOX_TITLE_COLOR);

    tft.setCursor(x + BOX_FROMREF_TITLE_X, y + BOX_FROMREF_TITLE_Y);
    tft.setTextSize(BOX_VALUE_SIZE);
    tft.setTextColor(BOX_VALUE_COLOR);
    tft.print(dtostrf(v, 2, p, buffer));
}