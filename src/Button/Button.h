#pragma once

#include <Arduino.h>

#include "State.h"
#include "debouncers/IDebouncer.h"

class Button
{
private:
    uint8_t _pin;
    // State _rawState;
    // unsigned long _currentTime;
    State _state;

public:
    Button(uint8_t pin) : _pin(pin) { pinMode(_pin, INPUT_PULLUP); }
    State debounce(IDebouncer &debouncer) {}
};