#include "PWM.h"

void PWM::tick()
{
    _currentTime = currentTimeDefinition();
    if (_currentTime % _tactLength < _tactLength * _dutyCycle)
    {
        digitalWrite(_pin, HIGH);
    }
    else
    {
        digitalWrite(_pin, LOW);
    }
}

void PWM::mapAnalogToDutyCycle(int analogValueRaw, const int MAX_VALUE)
{
    _dutyCycle = MIN_DUTY_CYCLE + (static_cast<float>(analogValueRaw) / static_cast<float>(MAX_VALUE)) * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE);
}
