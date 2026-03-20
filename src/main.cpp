#include <Arduino.h>

#include "led/Led.h"
#include "led/Blinker.h"
#include "button/Button.h"

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int LED_PIN = LED_BUILTIN;
constexpr int BUTTON_PIN = 4;

Led led(LED_PIN);
Button button(BUTTON_PIN);
Blinker blinker(led);

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  led.init();
  button.init();
}

void loop()
{
  if (button.getState())
  {
    blinker.nextBlinkMode();
    button.setState(UNCHANGED);
  }

  if (millis() % 1000 == 0)
  {
    Serial.println(blinker.getSelectedMode());
  }

  blinker.blink();
}
