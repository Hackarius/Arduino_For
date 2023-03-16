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

void writeText(char *text, uint8_t size, uint16_t color, int16_t posX, int16_t posY)
{
  tft.setCursor(posX, posY);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.setTextSize(size);
  tft.print(text);
}

void chargingVoltmeter()
{
  tft.fillRoundRect(5, (tft.height() / 2 - 10), (tft.width() - 10), 20, 5, ST77XX_WHITE);

  for (int i = 0; i < 10; i += 1)
  {
    tft.fillRoundRect(5 + ((tft.width() / 10) * i), (tft.height() / 2 - 9), (tft.width() / 10) - 1, 18, 5, ST77XX_GREEN);
    delay(WAIT_CHARGE);
  }
}

void setup(void)
{
  Serial.begin(9600);
  Serial.print(F("Welcome to Orsys!"));

  tft.initR(INITR_BLACKTAB);

  tft.fillScreen(TFT_BACKGROUND_COLOR);
  makeBoxWithTitle(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, "V en A0");

  // char msgTtl[6] = "ORSYS";
  // writeText(msgTtl, 2, ST7735_BLACK, (tft.width() / 2) - ((strlen(msgTtl) * SIZE_BNORMAL_CHAR) / 2), (tft.height() / 2) - (tft.height() / 6));

  // char msgPjt[15] = "Voltmeter test";
  // writeText(msgPjt, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(msgPjt) * SIZE_NORMAL_CHAR) / 2), (tft.height() / 2) + (tft.height() / 12));

  // char msgCprt[15] = "Copyright 2023";
  // writeText(msgCprt, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(msgCprt) * SIZE_NORMAL_CHAR) / 2), (tft.height() - tft.height() / 8));

  // char msgRev[15] = "Rev v0.1";
  // writeText(msgRev, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(msgRev) * SIZE_NORMAL_CHAR) / 2), (tft.height() - tft.height() / 14));
  // delay(2000);

  // tft.fillScreen(ST77XX_BLACK);
  // chargingVoltmeter();
  // delay(1000);

  // tft.fillScreen(ST77XX_BLACK);
  // char msgVolt[8] = "Tension";
  // writeText(msgVolt, 3, ST7735_RED, (tft.width() / 2) - ((strlen(msgVolt) * (SIZE_NORMAL_CHAR * 3)) / 2), (tft.height() / 20));

  // char msgPin[8] = "A0";
  // writeText(msgPin, 4, ST7735_BLUE, (tft.width() / 2) - ((strlen(msgPin) * (SIZE_NORMAL_CHAR * 4)) / 2), (tft.height() / 3));
  // Serial.println("End of the show");
}

void loop()
{
  setFloatValueInBox(BOX_A0_X, BOX_A0_Y, BOX_GENERIC_W, BOX_GENERIC_H, getResultVIn(analogRead(PIN_VOLTMETER)), BOX_GENERIC_VALUE_PREC);
  delay(1000);
}