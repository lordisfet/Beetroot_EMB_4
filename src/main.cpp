#include <Arduino.h>

#include "led/Led.h"
#include "led/Blinker.h"
#include "button/Button.h"

void printLog();

constexpr int MONITOR_BAUD_RATE = 115200;
constexpr int PRINT_DELAY = 100;

constexpr int BUTTON_PIN = 4;

constexpr int8_t RED_LED_PIN = 21;
constexpr int8_t GREEN_LED_PIN = 45;
constexpr int8_t BLUE_LED_PIN = 36;

constexpr int RED_LED_BLINK_TIME = 200;
constexpr int GREEN_LED_BLINK_TIME = 500;
constexpr int BLUE_LED_BLINK_TIME = 1000;

Button button(BUTTON_PIN);

Led redLed(RED_LED_PIN);
Led greenLed(GREEN_LED_PIN);
Led blueLed(BLUE_LED_PIN);

Blinker redLedBlinker(redLed, RED_LED_BLINK_TIME);
Blinker greenLedBlinker(greenLed, GREEN_LED_BLINK_TIME);
Blinker blueLedBlinker(blueLed, BLUE_LED_BLINK_TIME);

void setup()
{
  Serial.begin(MONITOR_BAUD_RATE);

  button.init();

  redLed.init();
  greenLed.init();
  blueLed.init();
}

void loop()
{
  if (button.getState())
  {
    redLedBlinker.blink();
    greenLedBlinker.blink();
    blueLedBlinker.blink();
  }
  else

    redLed.setState(OFF);
  greenLed.setState(OFF);
  blueLed.setState(OFF);
}

printLog();
}

void printLog()
{
  static unsigned long lastPrintTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastPrintTime >= PRINT_DELAY)
  {
    Serial.println((String)button.getState() + '\t' + (String)redLed.getState() +
                   '\t' + (String)greenLed.getState() + '\t' + (String)blueLed.getState());
    lastPrintTime = currentTime;
  }
}