/*
  Arduino Starter Kit -- Project 02
 */
 
int switchState = 0;

void setup() {                
  // Setup Input Pins
  pinMode(2, INPUT);
  
  // Setup Output Pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);  
}

void loop() {
  // Read the current button state
  switchState = digitalRead(2);
  
  if (switchState == LOW) {
    // The button is NOT pressed
    digitalWrite(3, HIGH);  // Green LED
    digitalWrite(4, LOW);   // Red LED
    digitalWrite(5, LOW);   // Red LED
    
  } else {
    // The button is pressed
    digitalWrite(3, LOW);  // Green LED
    digitalWrite(4, LOW);  // Red LED
    digitalWrite(5, HIGH); // Red LED

    delay(250);    
    
    // Toggle the LEDs
    digitalWrite(4, HIGH); // Red LED
    digitalWrite(5, LOW); // Red LED
    delay(250);
  }
}
