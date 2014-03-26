/*
  Arduino Starter Kit -- Project 15
 */

const int optoPin = 2;
const int statusPin = 13;

void setup() {
  pinMode(optoPin, OUTPUT);
  pinMode(statusPin, OUTPUT);
}

void loop() {
  
  // This is hooked up to an LED lamp
  // The optocoupler should act as a swithc
  
  digitalWrite(optoPin, HIGH);
  digitalWrite(statusPin, HIGH);
  delay(5000);
  
  digitalWrite(optoPin, LOW);
  digitalWrite(statusPin, LOW);
  delay(5000);
}
