#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Adafruit_BMP085.h>

#include "TFT_Framework.h"
#include "TFT_Positions.h"
#include "DS_1307.h"
#include "BMP_085.h"

#include "Config.h"

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9

#define WAITING 1000

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_BMP085 bmp;

void setup(void)
{
  Serial.begin(9600);

  #ifdef SCREEN_MODULE
    tft.initR(INITR_BLACKTAB);
  #endif

  #ifdef PRESS_SENSOR
    setupPressure();
  #endif

  #ifdef SCREEN_MODULE
    screenSetup();
  #endif
  
  delay(WAITING);

  #ifdef RTC_SENSOR
    readAndDisplayHourTime();
  #endif
}

void loop()
{
  #ifdef RTC_SENSOR
    readAndDisplayHourTime();
  #endif

  #ifdef PRESS_SENSOR
    Serial.println(readPressure());
  #endif

  #ifdef TEMP_SENSOR
    Serial.println(readTemp());
  #endif

  delay(WAITING);
}