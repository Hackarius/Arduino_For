#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "tft_visual_frame_framework.h"
#include "tft_positions.h"

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9
#define PI (float)3.1415926F

#define WAIT_CHARGE 100
#define PAS_CHARGE 8
#define SIZE_NORMAL_CHAR 6
#define SIZE_BNORMAL_CHAR 12

#define PIN_VOLTMETER A0

#define R1 2000
#define R2 560

#define MAX_VOLTAGE 22.857F
#define DEFAULT_VOLTAGE 5.0F
#define RATIO_VOLTAGE (float)(MAX_VOLTAGE / DEFAULT_VOLTAGE)
#define RATIO_ADC (float)(DEFAULT_VOLTAGE / 1024.0F)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

float getResultVIn(uint16_t vAdc)
{
  return RATIO_ADC * vAdc * RATIO_VOLTAGE;
}

void setup(void)
{
  Serial.begin(9600);
  Serial.print(F("Welcome to Orsys!"));

  tft.initR(INITR_BLACKTAB);

  tft.fillScreen(TFT_BACKGROUND_COLOR);
  makeBoxWithTitle(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, "V en A0");
  delay(1000);
}

void loop()
{
  setFloatValueInBox(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, getResultVIn(analogRead(PIN_VOLTMETER)), BOX_GENERIC_VALUE_PREC);
  delay(1000);
}