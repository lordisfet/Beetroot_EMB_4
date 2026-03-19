#pragma once

#include <Arduino.h>
#include <State.h>

static constexpr unsigned int DEFAULT_DEBOUNCE_DURATION = 100;

class Button
{
private:
    const int8_t pin;
    State state;
    unsigned int debounceTime;

public:
    Button(int8_t pin, State state = OFF, unsigned int debounceTime = DEFAULT_DEBOUNCE_DURATION) : pin(pin), state(state), debounceTime(debounceTime) {}

    void init() { pinMode(pin, INPUT_PULLDOWN); }
    State updateClick();
};