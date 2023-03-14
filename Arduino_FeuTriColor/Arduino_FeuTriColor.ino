#define PIN_GREEN (uint8_t) 3
#define PIN_YELLOW (uint8_t) 5
#define PIN_RED (uint8_t) 6

#define DELAY_LED 500

void writeOnLed(uint8_t PIN) {
  digitalWrite(PIN, HIGH);
  delay(DELAY_LED);
  digitalWrite(PIN, LOW);
}

void setup() {
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  writeOnLed(PIN_GREEN);
  writeOnLed(PIN_YELLOW);
  writeOnLed(PIN_RED);
}
