/*
  Arduino Starter Kit -- Project 11
 */
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
const int switchPin = 6;
int currSwitchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Generate a ");
  lcd.setCursor(0, 1);
  lcd.print("random number");
}
 
void loop() {
   currSwitchState = digitalRead(switchPin);
   
   if (currSwitchState != prevSwitchState) {
     if (currSwitchState == LOW) {
       reply = random(8);
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Random Number:");
       lcd.setCursor(0, 1);
       
       switch (reply) {
         case 0:
           lcd.print("Msg 00");
           break;
         case 1:
           lcd.print("Msg 01");
           break;
         case 2:
           lcd.print("Msg 02");
           break;
         case 3:
           lcd.print("Msg 03");
           break;
         default:
           lcd.print("Default Msg");

       }         
     }
   }
   
   prevSwitchState = currSwitchState;
}
 
