#ifndef _TFT_VISUAL_FRAME_FRAMEWORK_H_
#define _TFT_VISUAL_FRAME_FRAMEWORK_H_

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
void setFloatValueInBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float v, uint8_t p);

/**
 * @def create box and insert a title
 * 
 * @param x position in x on width
 * @param y position in y on height
 * @param w size of width
 * @param h size of height
 * @param t title of the box
*/
void makeBoxWithTitle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *t);

/**
 * @def create box
 * 
 * @param x position in x on width
 * @param y position in y on height
 * @param w size of width
 * @param h size of height
*/
void makeBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

void makeBand();

void makeBandWithHour(tmElements_t tm);

void setText(uint8_t x, uint8_t y, const char *t, uint16_t c, uint8_t s);

#endif