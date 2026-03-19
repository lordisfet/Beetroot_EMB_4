#pragma once

#include <Arduino.h>
#include <State.h>

class Led
{
private:
    int8_t pin;
    State state;

public:
    Led();
    Led(int8_t pin, State initialState = OFF)
    {
        this->pin = pin;
        state = initialState;
    };
    ~Led();

    int8_t getPin() { return pin; }
    void setPin(int8_t pin) { this->pin = pin; }
    State getState() { return state; }
    void setState(State state) { this->state = state; }
};