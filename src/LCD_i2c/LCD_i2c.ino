#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define NB_ROW 2
#define NB_COLUMN 16

#define PIN_VOLTMETER A0

#define R1 2000
#define R2 560

#define MAX_VOLTAGE 22.857F
#define DEFAULT_VOLTAGE 5.0F
#define RATIO_VOLTAGE (float)(MAX_VOLTAGE/DEFAULT_VOLTAGE)
#define RATIO_ADC (float)(DEFAULT_VOLTAGE/1024.0F)

#define WAIT_TIME 1000

uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t note[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrow[8] = {0x1,0x1,0x5,0x9,0x1f,0x8,0x4};
uint8_t eaccgrv[8] = {
    B01000,
    B00100,
    B01110,
    B10001,
    B11111,
    B10000,
    B01110,
    B00000
};
uint8_t eaccgrv2[8] = {0x8,0x4,0xe,0xf1,0xff,0xf0,0xe,0x0};

LiquidCrystal_I2C lcd(0x27, NB_COLUMN, NB_ROW);

float getResultVIn(uint16_t vAdc) {
    return RATIO_ADC * vAdc * RATIO_VOLTAGE;
}

void setup() {
    lcd.init();
    lcd.backlight();

    lcd.createChar(0, eaccgrv2);

    lcd.print("Orsys");
    lcd.setCursor(0, 1);
    lcd.print("Voltm");
    lcd.write((byte) 0);
    lcd.print("tre");

    delay(2000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Voltm");
    lcd.write((byte) 0);
    lcd.print("tre");
}  

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(getResultVIn(analogRead(PIN_VOLTMETER)));
    delay(WAIT_TIME);
}
