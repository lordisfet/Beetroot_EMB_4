#include <Arduino.h>

#include "clickCheckers/Checker.h"
#include "clickCheckers/WithoutDebounce.h"
#include "clickCheckers/TimeBasedDebounce.h"
#include "clickCheckers/StateBasedDebounce.h"

void printLog(Checker &ckeckerWithoutDebounce);

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int PRINT_DELAY = 100;

constexpr int BUTTON_PIN = 4;

WithoutDebounce ckrWithoutDebounce;
TimeBasedDebounce ckrTimeBasedDebounce;
StateBasedDebounce ckrStateBasedDebounce;

void IRAM_ATTR globalISR()
{
  State currentState = static_cast<State>(digitalRead(BUTTON_PIN));
  unsigned long currentTime = millis();

  ckrWithoutDebounce.onInterrupt(currentState, currentTime);
  ckrTimeBasedDebounce.onInterrupt(currentState, currentTime);
  ckrStateBasedDebounce.onInterrupt(currentState, currentTime);
}

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), globalISR, FALLING);
}

void loop()
{
  ckrStateBasedDebounce.update(static_cast<State>(digitalRead(BUTTON_PIN)), millis());

  printLog(ckrWithoutDebounce);
  printLog(ckrTimeBasedDebounce);
  printLog(ckrStateBasedDebounce);
}

void printLog(Checker &checker)
{
  int lastClickCount = checker.getLastClickCount();
  int currentClickCount = checker.getClickCount();
  if (lastClickCount != currentClickCount)
  {
    checker.setLastClickCount(currentClickCount);
    Serial.print(checker.getName() + '\t');
    Serial.print("Click count: ");
    Serial.println(currentClickCount);
  }
}