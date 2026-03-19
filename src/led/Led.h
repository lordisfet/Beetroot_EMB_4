#pragma once

#include <Arduino.h>
#include <State.h>

class Led
{
private:
    const int8_t pin;
    State state;

public:
    Led(int8_t pin, State initialState = OFF) : pin(pin), state(initialState) {};

    void updateLedStatus() { digitalWrite(pin, (state == ON) ? HIGH : LOW); }
    void init()
    {
        pinMode(pin, OUTPUT);
        updateLedStatus();
    }
};