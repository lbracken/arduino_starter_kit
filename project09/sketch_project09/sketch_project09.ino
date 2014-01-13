/*
  Arduino Starter Kit -- Project 09
 */
 
 const int switchPin = 2;
 const int motorPin = 9;
 
 void setup() {
   pinMode(switchPin, INPUT);   
   pinMode(motorPin, OUTPUT);
 }
 
 void loop() {
   int switchState = digitalRead(switchPin);
   
   if (switchState == HIGH) {
     digitalWrite(motorPin, HIGH);
   } else {
     digitalWrite(motorPin, LOW);
   }
 }

