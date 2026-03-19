#pragma once

#include <Arduino.h>
#include <State.h>

class Led
{
private:
    const int8_t pin;
    State state;

public:
    Led();
    Led(int8_t pin, State initialState = OFF) : pin(pin), state(initialState) {};
    ~Led();

    int8_t getPin() { return pin; }
    State getState() { return state; }
    void setState(State state) { this->state = state; }
    void init() { pinMode(pin, OUTPUT); }
};