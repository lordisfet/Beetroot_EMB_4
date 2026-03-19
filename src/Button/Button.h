#pragma once

#include <Arduino.h>
#include "ButtonState.h"

static constexpr unsigned int DEFAULT_DEBOUNCE_DURATION = 100;

class Button
{
private:
    const int8_t pin;
    ButtonState state;
    unsigned int debounceTime;

public:
    Button(int8_t pin, ButtonState = RELEASED, unsigned int debounceTime = DEFAULT_DEBOUNCE_DURATION)
        : pin(pin), state(state), debounceTime(debounceTime) {}

    void init() { pinMode(pin, INPUT_PULLDOWN); }
    ButtonState updateClick();
};