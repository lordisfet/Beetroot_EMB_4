#include <Arduino.h>
#include "FlashLedsMod.h"

FlashLedsMod::FlashLedsMod()
{
}

FlashLedsMod::FlashLedsMod(const int8_t* leds, int8_t count, int duration)
{
  this->leds = leds;
  this->count = count;
  this->duration = duration;
}

FlashLedsMod::~FlashLedsMod()
{
}

void FlashLedsMod::flashLed(int led, unsigned long start, unsigned int duration, unsigned int currentCycle) {
  if (currentCycle >= start && currentCycle < start + duration) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void FlashLedsMod::flashing(unsigned long currentCycle) {
  for (int i = 0; i < count; i++)
  {
    flashLed(leds[i], i * duration, duration, currentCycle);
  }
}