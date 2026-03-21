#include <Arduino.h>

#include "button/Button.h"
#include "PWM.h"

constexpr int8_t BOOT_BUTTON_PIN = 0;
constexpr int8_t PWM_PIN = 4;

Button button(BOOT_BUTTON_PIN);
PWM pwm(PWM_PIN, 20, MS, 0.5);

void setup()
{
}

void loop()
{
}
