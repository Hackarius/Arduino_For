/**
 * Serial waiting for read
 *
 * @param msTimeout "waiting time until user enter his name"
 */
void waitSerialUntilNotAvailable(uint16_t msTimeout = 10000) {
  uint16_t counter = 0;
  Serial.flush();

  while (Serial.available() == 0 && counter < msTimeout) {
    counter+=300;
    delay(300);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("Welcome to Test World !,\n Your name, please > ");

  waitSerialUntilNotAvailable();
  char inputName[15] = "No name !";

  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', inputName, 15);
    Serial.print("\nName chosed is > ");
    Serial.println(inputName);

    // while (Serial.available()) {
    //   char inputValue = Serial.read();
    //   Serial.print("\nChar received > ");
    //   Serial.println(inputValue);
    // }
  } else {
    Serial.println("\nNo name entered !");
    Serial.println(inputName);
  }
}

void loop() {}
