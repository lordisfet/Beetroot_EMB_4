#include <Arduino.h>

#include "led.h"

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int LED_PIN = LED_BUILTIN;
constexpr int BOOT_PIN = 0;

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
}