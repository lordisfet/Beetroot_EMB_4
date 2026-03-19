#include <Arduino.h>

#include "led/Led.h"
#include "led/Blinker.h"
#include "button/Button.h"

void calculateAvgIterationTime(double iterationTime);

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int LED_PIN = LED_BUILTIN;
constexpr int BOOT_PIN = 4;
constexpr int SAMPLE = 1000;

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
  static unsigned long startTime;
  static unsigned long finishTime;

  startTime = millis();

  if (!bootButton.updateClick())
  {
    blinker.nextBlinkMode();
  }

  blinker.blink();

  finishTime = millis();

  calculateAvgIterationTime(finishTime - startTime);
}

void calculateAvgIterationTime(double iterationTime)
{
  static int iterationsCounter = 0;
  static unsigned long timeOfSamplesIterations = 0;
  timeOfSamplesIterations += iterationTime;
  iterationsCounter++;

  if (iterationsCounter == SAMPLE)
  {
    Serial.println("Avg time for iteratio is: " + (String)(timeOfSamplesIterations / SAMPLE));
    iterationsCounter = 0;
    timeOfSamplesIterations = 0;
  }
}