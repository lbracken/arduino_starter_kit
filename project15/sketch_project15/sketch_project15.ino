/*
  Arduino Starter Kit -- Project 15
 */

const int optoPin = 2;

void setup() {
  pinMode(optoPin, OUTPUT);
}

void loop() {
  digitalWrite(optoPin, HIGH);
  delay(3000);
  digitalWrite(optoPin, LOW);
  delay(3000);
}
