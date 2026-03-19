#include <Arduino.h>

#include "led.h"

#define MONITOR_BAUD_RATE 115200

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
}