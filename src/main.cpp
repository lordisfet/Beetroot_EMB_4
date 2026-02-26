#include <Arduino.h>

#define BUTTON T20

volatile int16_t counter = 0;

unsigned long last_interrupt_time = 0;
bool last_button_state = HIGH;
int8_t debounce_time = 50; 

void IRAM_ATTR reaction() {
  if (last_button_state != digitalRead(BUTTON))
  {
    if (last_button_state == LOW)
    {
      unsigned int current_time = millis();

      if (current_time - last_interrupt_time > debounce_time)
      {
        counter++;
        last_interrupt_time = current_time;
        Serial.println("Counter: " + String(counter) + " at " + String((current_time / 1000.0 )) + " s");
      }
    }

    last_button_state = !last_button_state;
  }
}

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BUTTON), reaction, CHANGE);
}

void loop() {
}