#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#include "tft_visual_frame_framework.h"
#include "tft_positions.h"
#include "DS1307.h"

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9

#define WAITING 1000

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);

  screenSetup();
  delay(WAITING);
  readAndDisplayHourTime();
}

void loop()
{
  readAndDisplayHourTime();
  delay(WAITING);
}