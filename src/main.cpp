#include <Arduino.h>

#define BUTTON_LEFT T20

volatile int16_t counter_left = 0;

unsigned long last_interrupt_time = 0;
int8_t debounce_time = 50; 

void IRAM_ATTR reaction_left() {
  if (millis() - last_interrupt_time > debounce_time) {
    counter_left++;  
    Serial.println("\nLEFT Button Pressed! Count: " + String(counter_left));
  }
  last_interrupt_time = millis();
}

void setup() {
  pinMode(BUTTON_LEFT, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BUTTON_LEFT), reaction_left, FALLING);
}

void loop() {

}