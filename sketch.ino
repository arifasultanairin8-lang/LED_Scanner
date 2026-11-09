int ledDelay = 200;

void setup() {
  DDRD |= B11110000; 
  Serial.begin(9600);
}

void loop() {
  for (int pin = 4; pin <= 7; pin++) {
    turnOnLED(pin);
    checkSerialSpeed();
  }
  
  for (int pin = 6; pin >= 5; pin--) {
    turnOnLED(pin);
    checkSerialSpeed();
  }
}

void turnOnLED(int targetPin) {
  PORTD = (PORTD & B00001111) | (1 << targetPin);
  delay(ledDelay);
}

void checkSerialSpeed() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    
    if (input == 'f') {
      if (ledDelay > 50) {
        ledDelay -= 25;
      }
    } 
    else if (input == 's') {
      ledDelay += 25;
    }
    
    Serial.print("New Speed: ");
    Serial.print(ledDelay);
    Serial.println(" ms");
  }
}
