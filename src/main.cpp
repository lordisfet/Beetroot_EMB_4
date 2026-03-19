#include <Arduino.h>

#include "led/Led.h"
#include "led/Blinker.h"
#include "button/Button.h"

void IRAM_ATTR handleButtonInterrupt();

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int LED_PIN = LED_BUILTIN;
constexpr int BOOT_PIN = 4;

Led led(LED_PIN);
Button bootButton(BOOT_PIN);
Blinker blinker(led);

volatile bool buttonFlag = false;

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  led.init();
  bootButton.init();

  attachInterrupt(digitalPinToInterrupt(BOOT_PIN), handleButtonInterrupt, FALLING);
}

void loop()
{
  if (buttonFlag)
  {
    blinker.nextBlinkMode();
    buttonFlag = false;
  }

  blinker.blink();
}

void IRAM_ATTR handleButtonInterrupt()
{
  buttonFlag = !bootButton.updateClick();
}
