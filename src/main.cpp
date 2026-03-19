#include <Arduino.h>

#include "led/Led.h"
#include "led/Blinker.h"
#include "button/Button.h"

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int LED_PIN = LED_BUILTIN;
constexpr int BOOT_PIN = 4;

Led led(LED_PIN);
Button bootButton(BOOT_PIN);
Blinker blinker(led);

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  led.init();
  bootButton.init();
}

void loop()
{
  if (bootButton.updateClick())
  {
    blinker.nextBlinkMode();
    Serial.println(millis());
  }

  blinker.blink();
}