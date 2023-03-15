

#define PIN_POT (uint8_t) A5

#define PIN_BUTTON (uint8_t) 2
#define PIN_GREEN (uint8_t) 3
#define PIN_YELLOW (uint8_t) 5
#define PIN_RED (uint8_t) 6

#define WAIT_TIME 1000
#define DELAY_LED 500

void writeOnLed(uint8_t PIN) {
  digitalWrite(PIN, HIGH);
  delay(DELAY_LED);
  digitalWrite(PIN, LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(PIN_BUTTON);

  if (buttonState) {
    writeOnLed(PIN_GREEN);
    writeOnLed(PIN_YELLOW);
    writeOnLed(PIN_RED);

    Serial.println("LED activated");
  } else {
    Serial.println("Not activated");

    delay(WAIT_TIME);
  }
}
