/*
  Arduino Starter Kit -- Project 06
 */
 
const int ledPin = 13;

int sensorLow = 1023;
int sensorHigh = 0;
int sensorValue = sensorLow;



void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    } else if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  digitalWrite(ledPin, LOW);
  
  // Output the calibration values
  Serial.begin(9600);
  Serial.print("Sensor High/Low: ");
  Serial.print(sensorHigh);
  Serial.print(", ");
  Serial.println(sensorLow);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  
  delay(10);
}

