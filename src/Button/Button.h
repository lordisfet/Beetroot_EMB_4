#pragma once

#include <Arduino.h>
#include "enums/ButtonState.h"

static constexpr unsigned int DEFAULT_DEBOUNCE_DURATION = 100;

class Button
{
private:
    const int8_t pin;
    unsigned int debounceTime;

public:
    Button(int8_t pin, unsigned int debounceTime = DEFAULT_DEBOUNCE_DURATION)
        : pin(pin), debounceTime(debounceTime) {}

    ButtonState getState() { return static_cast<ButtonState>(digitalRead(pin)); }
    void init() { pinMode(pin, INPUT_PULLUP); }
    ButtonState updateClick();
};