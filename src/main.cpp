#include <Arduino.h>

#include "button/Button.h"
#include "pwm/PWM.h"

constexpr int MONITOR_BOUD_RATE = 115200;

constexpr int8_t BUTTON_PIN = 4;
constexpr int8_t DEBOUNCE_TIME = 50;

constexpr int8_t PWM_PIN = 45;

constexpr int8_t HANDLE_PIN = 3;
constexpr int8_t POTENTIOMETER_RESOLUTION = 12;
constexpr int16_t

    constexpr int TACT_LENGHT = 20;
constexpr float DUTY_CYCLE = 1;
constexpr DecimalPrefix PREFIX = MS;

Button button(BUTTON_PIN, DEBOUNCE_TIME, UNCHANGED);
PWM pwm(PWM_PIN, TACT_LENGHT, PREFIX, DUTY_CYCLE);

void setup()
{
  Serial.begin(MONITOR_BOUD_RATE);

  button.init();
  pwm.init();

  pinMode(HANDLE_PIN, INPUT_PULLDOWN);
}

void loop()
{
  if (button.getState())
  {
    pwm.tick();
  }
  else
  {
    pwm.setPWMLevel(LOW);
  }

  // static unsigned long lastPrintTime = 0;
  // if (millis() - lastPrintTime > 250)
  // {
  //   Serial.println((String)analogReadRaw(HANDLE_PIN) + '\t' + (String)button.getState());
  //   lastPrintTime = millis();
  // }
}
