#pragma once

#include <Arduino.h>

enum DecimalPrefix
{
    MCS,
    MS
};

class PWM
{
private:
    int8_t _pin;
    const unsigned int _tactLength;
    DecimalPrefix _tactLengthType;
    float _dutyCycle;

    unsigned long _currentTime;

    unsigned long currentTimeDefinition() { return (_tactLengthType == MS) ? millis() : micros(); }

public:
    static constexpr float MIN_DUTY_CYCLE = 0;
    static constexpr float MAX_DUTY_CYCLE = 1;

    PWM(int8_t pin, unsigned int tactLength, DecimalPrefix tactLengthType, float dutyCycle)
        : _pin(pin), _tactLength(tactLength), _tactLengthType(tactLengthType), _dutyCycle(dutyCycle) {}

    void setPWMLevel(bool state) { digitalWrite(_pin, state); }
    float getDutyCycle() { return _dutyCycle; }

    void init() { pinMode(_pin, OUTPUT); }
    void tick();
    void mapAnalogToDutyCycle(int analogValueRaw, const int MAX_VALUE);
};