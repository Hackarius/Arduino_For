#ifndef _TFT_VISUAL_FRAME_FRAMEWORK_H_
#define _TFT_VISUAL_FRAME_FRAMEWORK_H_

void screenSetup(void);

void makeBoxWithTitle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *t);
void makeBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

void makeBand(void);
void makeBandWithHour(tmElements_t tm);

void setFloatValueInBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float v, uint8_t p);
void setText(uint8_t x, uint8_t y, const char *t, uint16_t c, uint8_t s);

#endif