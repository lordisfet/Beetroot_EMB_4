#include <Arduino.h>

#include "button/Button.h"
#include "button/clickCheckers/WithoutDebounce.h"
#include "button/clickCheckers/TimeBasedDebounce.h"

void printLog(IDebouncer &ckeckerWithoutDebounce);

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int PRINT_DELAY = 100;

constexpr int BUTTON_PIN = 4;

Button button(BUTTON_PIN);

WithoutDebounce ckrWithoutDebounce;
TimeBasedDebounce ckrTimeBasedDebounce;

void IRAM_ATTR globalISR()
{
  State currentState = static_cast<State>(digitalRead(BUTTON_PIN));
  unsigned long currentTime = millis();

  button.clickCheck(ckrWithoutDebounce, currentState, currentTime);
  button.clickCheck(ckrTimeBasedDebounce, currentState, currentTime);
}

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), globalISR, FALLING);
}

void loop()
{
  printLog(ckrWithoutDebounce);
  printLog(ckrTimeBasedDebounce);
}

void printLog(IDebouncer &ckeckerWithoutDebounce)
{
  int lastClickCount = ckeckerWithoutDebounce.getLastClickTime();
  int currentClickCount = ckeckerWithoutDebounce.getCount();
  if (lastClickCount != currentClickCount)
  {
    ckeckerWithoutDebounce.setLastClickTime(currentClickCount);
    Serial.print(ckeckerWithoutDebounce.getName() + '\t');
    Serial.print("Click count: ");
    Serial.println(currentClickCount);
  }
}