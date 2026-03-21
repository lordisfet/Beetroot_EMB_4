#pragma once

#include <Arduino.h>

enum RelayState
{
    TURN_OFF,
    TURN_ON
};

class Relay
{
private:
    int8_t _pin;
    RelayState _state;

public:
    Relay(int8_t pin, RelayState state = TURN_OFF) : _pin(pin), _state(state) {};

    void setState(RelayState state) { _state = state; }
    RelayState getState() { return _state; }
};