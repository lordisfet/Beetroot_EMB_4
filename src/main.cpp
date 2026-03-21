#include <Arduino.h>

#include "button/Button.h"
#include "PWM.h"

constexpr int MONITOR_BOUD_RATE = 115200;

constexpr int8_t BUTTON_PIN = 0;
constexpr int8_t PWM_PIN = 45;
constexpr int8_t HANDLE_PIN = 4;

constexpr int TACT_LENGHT = 20;
constexpr float DUTY_CYCLE = .5;

Button button(BUTTON_PIN);
PWM pwm(PWM_PIN, TACT_LENGHT, MS, DUTY_CYCLE);

void setup()
{
    Serial.begin(MONITOR_BOUD_RATE);

    button.init();
    pwm.init();
}

void loop()
{
    if (button.getState())
    {
        digitalWrite(PWM_PIN, HIGH);
        // pwm.tick();
    }
    else
    {
        digitalWrite(PWM_PIN, LOW);
    }

    static unsigned long lastPrintTime = 0;
    if (millis() - lastPrintTime >= 1000)
    {
        lastPrintTime = millis();

        Serial.println(button.getState());
    }
}
