/**
 * Serial waiting for read
 *
 * @param msTimeout "waiting time until user enter his name"
 */
void waitSerialUntilNotAvailable(uint16_t msTimeout) {
  Serial.flush();

  while (Serial.available() == 0) {
    delay(300);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("Welcome to Test World !,\n Your name, please > ");

  waitSerialUntilNotAvailable(6000);

  if (Serial.available() > 0) {
    
    while (Serial.available()) {
      char inputValue = Serial.read();
      Serial.print("\nChar received > ");
      Serial.println(inputValue);
    }
    
  } else {
    Serial.println("\nNo name entered !");
  }
}

void loop() {}
