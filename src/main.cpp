#include <Arduino.h>

int redLed = 4;
int blueLed = 17;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  digitalWrite(redLed, HIGH);
  delay(130);
  digitalWrite(blueLed, LOW);
  delay(1000);
  digitalWrite(blueLed, HIGH);   
  delay(130);                  
  digitalWrite(redLed, LOW);                 
  delay(1000);                     
}
