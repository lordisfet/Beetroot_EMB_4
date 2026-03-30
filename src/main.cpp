#include <Arduino.h>

#include "button/Button.h"
#include "button/debouncers/InterruptWithoutDebounce.h"

void printLog();

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int PRINT_DELAY = 100;

constexpr int BUTTON_PIN = 4;

Button button(BUTTON_PIN);
IDebouncer debouncer = InterruptWithoutDebounce();

void IRAM_ATTR globalISR()
{
  button.clickCheck(debouncer, static_cast<State>(digitalRead(BUTTON_PIN)), millis());
}

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), globalISR, FALLING);
}

void loop()
{

  printLog();
}

void printLog()
{
}