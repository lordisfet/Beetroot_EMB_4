#pragma once

#include <Arduino.h>
#include "Led.h"
#include "enums/LedState.h"

class Led
{
private:
    const int8_t pin;
    LedState state;

public:
    Led(int8_t pin, LedState initialState = OFF) : pin(pin), state(initialState) {};

    int8_t getPin() { return pin; }
    LedState getState() { return state; }
    void setState(LedState newState)
    {
        state = newState;
        digitalWrite(pin, (state == ON) ? HIGH : LOW);
    }
    void init()
    {
        pinMode(pin, OUTPUT);
        setState(state);
    }
};