#include <Arduino.h>

void flashLed(int led, unsigned long start, unsigned int duration, unsigned int currentCycle);

int redLed = 4;
int blueLed = 17;
int greenLed = 10;
unsigned int duration = 1000;
unsigned int totalCycles = 3000; // Duration for which the LED will be on (in milliseconds)

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
    unsigned int currentCycle = millis() % totalCycles; // Get the current cycle time

    flashLed(redLed, 0, duration, currentCycle);
    flashLed(blueLed, 1000, duration, currentCycle);
    flashLed(greenLed, 2000, duration, currentCycle);
}

void flashLed(int led, unsigned long start, unsigned int duration, unsigned int currentCycle) {
  unsigned long now = millis();
  if (currentCycle >= start && currentCycle < start + duration) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
