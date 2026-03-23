#include <Arduino.h>

#include "button/Button.h"

constexpr int MONITOR_BOUD_RATE = 115200;

constexpr int8_t BUTTON_PIN = 4;
constexpr int8_t DEBOUNCE_TIME = 50;

constexpr int8_t RELAY_CONTROLL_PIN = 21;
bool relayControlPinState = HIGH;
constexpr int8_t RELAY_INPUT_PIN = 2;

Button button(BUTTON_PIN, DEBOUNCE_TIME);

void setup()
{
  Serial.begin(MONITOR_BOUD_RATE);

  button.init();

  pinMode(RELAY_CONTROLL_PIN, OUTPUT);
  digitalWrite(RELAY_CONTROLL_PIN, relayControlPinState);
  pinMode(RELAY_INPUT_PIN, INPUT_PULLDOWN);
}

void loop()
{
  unsigned long currentTime = millis();
  static unsigned long lastActiveTime = 0;
  if (currentTime - lastActiveTime >= 1000)
  {
    lastActiveTime = currentTime;
    relayControlPinState = !relayControlPinState;
    digitalWrite(RELAY_CONTROLL_PIN, relayControlPinState);
    Serial.println(relayControlPinState);
  }
}
