#include <LiquidCrystal.h>

#define PIN_VOLTMETER A0

#define R1 2000
#define R2 560

#define MAX_VOLTAGE 22.857F
#define DEFAULT_VOLTAGE 5.0F
#define RATIO_VOLTAGE (float)(MAX_VOLTAGE/DEFAULT_VOLTAGE)
#define RATIO_ADC (float)(DEFAULT_VOLTAGE/1024.0F)

#define WAIT_TIME 100

byte CARAC_E_ACC_GRAVE[8] = {
    B01000,
    B00100,
    B01110,
    B10001,
    B11111,
    B10000,
    B01110,
    B00000
};

byte CARAC_OHM[8] = {
    B00000,
    B00000,
    B01110,
    B10001,
    B01010,
    B11011,
    B00000,
    B00000
};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float getResultVIn(uint16_t vAdc) {
    return RATIO_ADC * vAdc * RATIO_VOLTAGE;
}

void setup() {
    lcd.createChar(0, CARAC_E_ACC_GRAVE);
    lcd.createChar(1, CARAC_OHM);

    lcd.begin(16, 2);
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
    lcd.print("tre :");
}  

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(getResultVIn(analogRead(PIN_VOLTMETER)));
    lcd.print(" "),
    lcd.write((byte) 1);
    delay(WAIT_TIME);
}
