/*
  Arduino Starter Kit -- Project 08
 */

int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 1000;

void setup() {
  for (int pin=2; pin < 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if(currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
 
    if (led >= 7) {
      led == 7;
    }
  }
  
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int pin=2; pin < 8; pin++) {
      digitalWrite(pin, LOW);
    }
    
    led = 2;
    previousTime = currentTime;
  }
  
  prevSwitchState = switchState;
}
    
