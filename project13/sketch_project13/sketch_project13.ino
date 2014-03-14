/*
  Arduino Starter Kit -- Project 13
 */
#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 700;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW); 
  }
  
  delay(25);
}
