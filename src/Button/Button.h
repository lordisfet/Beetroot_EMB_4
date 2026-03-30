#pragma once

#include <Arduino.h>

#include "State.h"
#include "debouncers/IDebouncer.h"

class Button
{
private:
    uint8_t _pin;
    State _state;

public:
    Button(uint8_t pin, State state = State::RELEASED) : _pin(pin), _state(state) { pinMode(_pin, INPUT_PULLUP); }

    State getState() { return _state; }

    void clickCheck(IDebouncer &debouncer, State rawState, unsigned long currentTime) { _state = debouncer.update(rawState, currentTime); }
};