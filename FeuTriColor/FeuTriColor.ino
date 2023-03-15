#define PIN_POT A5

#define PIN_BUTTON (uint8_t) 2
#define PIN_GREEN (uint8_t) 3
#define PIN_YELLOW (uint8_t) 5
#define PIN_RED (uint8_t) 6

#define MAX_VAL_POT 1024.0F
#define MAX_VOLTAGE 5
#define WAIT_TIME 1000
#define DELAY_LED 500

void writeOnLed(uint8_t PIN) {
  digitalWrite(PIN, HIGH);
  delay(DELAY_LED);
  digitalWrite(PIN, LOW);
}

/**
  * Convert value from potentiometer in voltage
  * @param potentiometerValue value read from the potentiometer
  * @param vRef voltage reference in the board
  * @return float
  */
float getPotentiometerRatio(uint16_t potentiometerValue, float vRef = MAX_VOLTAGE) {
  return vRef / MAX_VAL_POT * (float)potentiometerValue;
}

/**
  * Read value from potentiometer
  * Display value from potentiometer and value in voltage
  * @return void
  */
void readPotentiometer() {
  int potentiometerValue = analogRead(PIN_POT);
  Serial.print("Value from potentiometer > ");
  Serial.println(potentiometerValue);

  // Return value like (1.00, 2.00, ..., 5.00)
  // float voltValue = map(potentiometerValue, 0, 1023, 0, 5);

  float voltValue = getPotentiometerRatio(potentiometerValue);
  Serial.print("Value in volt > ");
  Serial.println(voltValue);
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
    readPotentiometer();

    writeOnLed(PIN_GREEN);
    writeOnLed(PIN_YELLOW);
    writeOnLed(PIN_RED);

    Serial.println("LED activated");
  } else {
    Serial.println("Not activated");

    delay(WAIT_TIME);
  }
}
