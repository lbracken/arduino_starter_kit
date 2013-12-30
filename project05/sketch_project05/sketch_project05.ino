/*
  Arduino Starter Kit -- Project 05
 */
 
#include <Servo.h>

const int potPin = A0;

Servo myServo; 
int potVal;
int angle;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 179);
  myServo.write(angle);
  
  // Write debug information
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("\t Angle: ");
  Serial.println(angle); 
  
  delay(100);
}

