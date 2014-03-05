/*
  Arduino Starter Kit -- Project 12
 */
 
 #include <Servo.h>
 
 Servo myServo;
 
 const int peizo = A0;
 const int switchPin = 2;
 const int ledYellow = 4;
 const int ledGreen = 3;
 const int ledRed = 5;
 
 int knockVal;
 int switchVal;
 
 const int quietKnock = 250;
 const int loudKnock = 400;
 
 boolean locked = false;
 int knockCount = 0;
 
 void setup() {
   
   myServo.attach(9);
   myServo.write(0);
   
   pinMode(switchPin, INPUT);
   pinMode(ledYellow, OUTPUT);
   pinMode(ledGreen, OUTPUT);
   pinMode(ledRed, OUTPUT);   
   digitalWrite(ledGreen, HIGH);
   
   Serial.begin(9600);
   Serial.println("The box is unlocked");
 }
 
void loop() {
  if (!locked) {
    switchVal = digitalRead(switchPin);
    
    if(switchVal == HIGH) {
      locked = true;
      knockCount = 0;
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      
      myServo.write(90);
      Serial.println("The box is locked");
      delay(1000);
    }
  }
  
  if (locked) {
    knockVal = analogRead(peizo);
    
    if (knockCount < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        knockCount++;
      }
    }
    
    if (knockCount >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      Serial.println("The box is unlocked!"); 
    }
  }
}

boolean checkForKnock(int value) {
  Serial.println(value);
  
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(ledYellow, HIGH);
    delay(50);
    digitalWrite(ledYellow, LOW);
    Serial.println("******* Registered as knock ********* ");
    return true;
    
  } else {
    return false;
  } 
}
   
