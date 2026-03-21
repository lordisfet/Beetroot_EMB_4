#include <Arduino.h>

enum TactLengthType
{
    MCS,
    MS
};

class PWM
{
private:
    int8_t _pin;
    const unsigned int _tactLength;
    TactLengthType _tactLengthType;
    double _dutyCycle;

    static unsigned long currentTime;

    unsigned long currentTimeDefinition()
    {
        return (_tactLengthType == MS) ? millis() : micros();
    }

public:
    static constexpr double MIN_DUTY_CYCLE = 0.001;
    static constexpr double MAX_DUTY_CYCLE = 1.;

    PWM(int8_t pin, unsigned int tactLength, TactLengthType tactLengthType, double dutyCycle)
        : _pin(pin), _tactLength(tactLength), _tactLengthType(tactLengthType), _dutyCycle(dutyCycle) {}

    void init() { pinMode(_pin, OUTPUT); }
    void tick()
    {

        if (currentTime % _tactLength < _tactLength * _dutyCycle)
        {
            digitalWrite(_pin, HIGH);
        }
        else
        {
            digitalWrite(_pin, LOW);
        }
    };
};