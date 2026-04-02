#include <Arduino.h>

#include "clickCheckers/Checker.h"
#include "clickCheckers/WithoutDebounce.h"
#include "clickCheckers/TimeBasedDebounce.h"
#include "clickCheckers/StateBasedDebounce.h"
#include "clickCheckers/PollingDebounce.h"

void printLog(Checker &ckeckerWithoutDebounce);

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int PRINT_DELAY = 100;

constexpr int BUTTON_PIN = 4;

WithoutDebounce ckrWithoutDebounce;
TimeBasedDebounce ckrTimeBasedDebounce;
StateBasedDebounce ckrStateBasedDebounce;
PollingDebounce ckrPollingDebounce;

State currentState;
unsigned long currentTime;
volatile int mainTest = 0;

void IRAM_ATTR globalISR()
{
  currentState = static_cast<State>(digitalRead(BUTTON_PIN));
  currentTime = millis();

  mainTest++;
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
  currentState = static_cast<State>(digitalRead(BUTTON_PIN));
  currentTime = millis();

  ckrStateBasedDebounce.update(currentState, currentTime);
  ckrPollingDebounce.update(currentState, currentTime);

  printLog(ckrWithoutDebounce);
  printLog(ckrTimeBasedDebounce);
  printLog(ckrStateBasedDebounce);
  printLog(ckrPollingDebounce);
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
    Serial.println("Main test count: ");
    Serial.println(mainTest);
  }
}