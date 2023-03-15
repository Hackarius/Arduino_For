#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9
#define PI (float) 3.1415926F

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void writeText(char *text, uint8_t size, uint16_t color, int16_t posX, int16_t posY)
{
  tft.setCursor(posX, posY);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.setTextSize(size);
  tft.print(text);
}

void testlines(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(tft.width() / 2, tft.height() / 2, x, 0, color);
    delay(0);
  }

  for (int16_t y= 0; y < 0; y -=6) {
    tft.drawLine(tft.width() / 2, tft.height() / 2, tft.width(), y, color);
    delay(0);
  }

  for (int16_t x=tft.width(); x >= 0; x -=6) {
    tft.drawLine(tft.width() / 2, tft.height() / 2, x, tft.height(), color);
    delay(0);
  }

  for (int16_t y=0; y < tft.height(); y +=6) {
    tft.drawLine(tft.width() / 2, tft.height() / 2, 0, y, color);
    delay(0);
  }
}

void setup(void)
{
  Serial.begin(9600);
  Serial.print(F("Welcome to Orsys!"));

  tft.initR(INITR_BLACKTAB);

  tft.fillScreen(ST77XX_WHITE);
  char titleMessage[6] = "ORSYS";
  writeText(titleMessage, 2, ST7735_BLACK, (tft.width() / 2) - ((strlen(titleMessage)*12) / 2), (tft.height() / 2) - 30);

  char messageProject[15] = "Voltmeter test";
  writeText(messageProject, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(messageProject)*6) / 2), (tft.height() / 2) + 20);

  char messageCopyright[15] = "Copyright 2023";
  writeText(messageCopyright, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(messageCopyright)*6) / 2), (tft.height() / 2) + 40);

  char messageRev[15] = "Rev v0.1";
  writeText(messageRev, 1, ST7735_BLACK, (tft.width() / 2) - ((strlen(messageRev)*6) / 2), (tft.height() / 2) + 50);
  delay(2000);

  tft.fillScreen(ST77XX_BLACK);
  testlines(ST77XX_GREEN);
  delay(1000);

  tft.fillScreen(ST77XX_BLACK);
  Serial.println("End of the show");
}

void loop()
{
}

void tftPrintTest()
{
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_GREEN);
  tft.print(PI, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(ST77XX_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(ST77XX_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(" seconds.");
}