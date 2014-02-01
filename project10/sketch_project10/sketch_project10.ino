/*
  Arduino Starter Kit -- Project 10
 */
 
 const int controlPin1 = 2;
 const int controlPin2 = 3;
 const int enablePin = 9;
 const int directionSwitchPin = 4;
 const int onOffSwitchStatePin = 5;
 const int potPin = A0;
 
 int currOnOffSwitchState = 0;
 int prevOnOffSwitchState = 0;
 int currDirectionSwitchState = 0;
 int prevDirectionSwitchState = 0;
 
 int motorEnabled = 0;
 int motorSpeed = 0;
 int motorDirection = 1;
 
 void setup() {
   // Input pins
   pinMode(directionSwitchPin, INPUT);
   pinMode(onOffSwitchStatePin, INPUT);
   
   // Output pins
   pinMode(controlPin1, OUTPUT);   
   pinMode(controlPin2, OUTPUT);
   pinMode(enablePin, OUTPUT);
   
   digitalWrite(enablePin, LOW);
 }
 
 void loop() {
   
   // Read current pin values
   currOnOffSwitchState = digitalRead(onOffSwitchStatePin);
   delay(1);
   currDirectionSwitchState = digitalRead(directionSwitchPin);
   motorSpeed = analogRead(potPin) / 4;
   
   if ((currOnOffSwitchState != prevOnOffSwitchState) && (currOnOffSwitchState == HIGH)) {
     motorEnabled = !motorEnabled;
   }

   if ((currDirectionSwitchState != prevDirectionSwitchState) && (currDirectionSwitchState == HIGH)) {
     motorDirection = !motorDirection;
   }
   
   if (motorDirection == 1) {
     digitalWrite(controlPin1, HIGH);
     digitalWrite(controlPin2, LOW);     
   } else {
     digitalWrite(controlPin1, LOW);
     digitalWrite(controlPin2, HIGH);     
   }
   
   if (motorEnabled == 1) {
     analogWrite(enablePin, motorSpeed);
   } else {
     analogWrite(enablePin, 0);
   }
   
   prevOnOffSwitchState = currOnOffSwitchState;
   prevDirectionSwitchState != currDirectionSwitchState;
 }

