#pragma once

#include <Arduino.h>
#include <State.h>

class Button
{
private:
    const int8_t pin;
    State state;
    unsigned int debounceTime;

public:
    Button(int8_t pin, State state = OFF, unsigned int debounceTime) : pin(pin), state(state), debounceTime(debounceTime) {}

    void init() { pinMode(pin, INPUT_PULLUP); }
    State updateClick();
};