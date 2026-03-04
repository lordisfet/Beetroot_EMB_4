#include <Arduino.h>
#include <OneButton.h>

#include "FlashLedsMod.h"

#define SERIAL_BAUD_RATE 115200

void generateTestPatterns(const int8_t* newLeds, const int8_t ledCount, FlashLedsMod* flashLedsMods, 
  const int8_t modscount, unsigned int maxDuration);
void flashingModSelector(bool isNext);

const int8_t redLed = 4;
const int8_t greenLed = 17;
const int8_t blueLed = 10;
const int8_t leds[] = {redLed, greenLed, blueLed};

const int8_t ledCount = sizeof(leds) / sizeof(leds[0]);   
const int8_t flashingModsCount = 6;
FlashLedsMod flashLedsMods[flashingModsCount]; // 0 using for turn off all leds, 1-5 for different flashing modes
int8_t currentFlashingModIndex = 0;

const int8_t bootButton = 0;
const int8_t externalButton = 21;
unsigned long currentCycle = 0;

OneButton oneButtonBoot(bootButton, true);
OneButton oneButtonExternal(externalButton, true);
bool isBootButtonClicked = false;
bool isExternalButtonClicked = false;

void handleBootClick() {
  isBootButtonClicked = true;
}

void handleExternalClick() {
  isExternalButtonClicked = true;
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(bootButton, INPUT_PULLUP);
  pinMode(externalButton, INPUT_PULLUP);

  oneButtonBoot.attachClick(handleBootClick);
  oneButtonExternal.attachClick(handleExternalClick);

  int minDuration = 200;
  int maxDuration = 1000;
  generateTestPatterns(leds, ledCount, flashLedsMods, flashingModsCount, maxDuration);
}

void loop() {
  if (isBootButtonClicked)
  {
    flashingModSelector(false);
    Serial.printf("Boot button clicked, changing flashing mode down to: %d, led duration: %d\n", 
    currentFlashingModIndex, flashLedsMods[currentFlashingModIndex].getDuration());
    isBootButtonClicked = false;
  }
  if (isExternalButtonClicked)
  {
    flashingModSelector(true);
    Serial.printf("External button clicked, changing flashing mode up to: %d, led duration: %d\n", 
    currentFlashingModIndex, flashLedsMods[currentFlashingModIndex].getDuration());
    isExternalButtonClicked = false;
  }
  
  currentCycle = millis() % flashLedsMods[currentFlashingModIndex].getTotalCycles();
  flashLedsMods[currentFlashingModIndex].flashing(currentCycle);
  oneButtonBoot.tick();
  oneButtonExternal.tick();
}

void generateTestPatterns(const int8_t* newLeds, const int8_t ledCount, FlashLedsMod* flashLedsMods,
  const int8_t modscount, unsigned int maxDuration) {
  for (int i = 0; i < modscount; i++)
  {
    flashLedsMods[i].setLeds(newLeds, ledCount);
    flashLedsMods[i].setDuration(i * (maxDuration / (modscount - 1)));
  }
}

void flashingModSelector(bool isNext) {
  if (isNext)
  {
    currentFlashingModIndex++;
  }
  else 
  {
    currentFlashingModIndex--;
    if (currentFlashingModIndex < 0)
    {
      currentFlashingModIndex = flashingModsCount - 1;
    }
  }

  currentFlashingModIndex %= flashingModsCount;
}
