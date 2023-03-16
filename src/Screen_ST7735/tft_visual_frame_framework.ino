#include <Arduino.h>
#include <Adafruit_ST77XX.h>
#include "tft_visual_frame_framework.h"
#include "tft_positions.h"

void setFloatValueInBox(uint8_t, uint8_t, uint8_t, uint8_t, float, uint8_t);

/**
 * @param x position in x on width
 * @param y position in y on height
 * @param t title of the box
 * @param c color of the text
 * @param s size for the text
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
    setText(x + BOX_FROMREF_TITLE_X, y + BOX_FROMREF_TITLE_Y, t, BOX_TITLE_COLOR, BOX_TITLE_SIZE);
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
    makeBox(x, y, w, h);
    setText(x + BOX_FROMREF_VALUE_X, y + BOX_FROMREF_VALUE_Y, dtostrf(v, 2, p, buffer), BOX_VALUE_COLOR, BOX_VALUE_SIZE);
}