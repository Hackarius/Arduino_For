#define PIN_VOLTMETER A0

#define R1 2000
#define R2 560

#define MAX_VOLTAGE 22.857F
#define DEFAULT_VOLTAGE 5.0F
#define RATIO_VOLTAGE (float)(MAX_VOLTAGE/DEFAULT_VOLTAGE)
#define RATIO_ADC (float)(DEFAULT_VOLTAGE/1024.0F)

#define WAIT_TIME 1000

float getResultVIn(uint16_t vAdc) {
    return RATIO_ADC * vAdc * RATIO_VOLTAGE;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("Value read > ");
    float res = getResultVIn(analogRead(PIN_VOLTMETER));
    Serial.println(res);

    delay(WAIT_TIME);
}