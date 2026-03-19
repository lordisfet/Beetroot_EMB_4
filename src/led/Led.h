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

    int8_t getPin() { return pin };
    State getState() { return state };
    void setState(State state) { digitalWrite(pin, (state == ON) ? HIGH : LOW); }
    void init()
    {
        pinMode(pin, OUTPUT);
        setState(state);
    }
};