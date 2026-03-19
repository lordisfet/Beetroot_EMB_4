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
    Button();
    Button(int8_t pin, State state = OFF, unsigned int debounceTime) : pin(pin), state(state), debounceTime(debounceTime) {}
    ~Button();

    int8_t getPin() { return pin; }
    State getState() { return state; }
    void setState(State state) { this->state = state; }
    unsigned int getDebounceTime() { return debounceTime; }
    void setDebounceTime(unsigned int debounceTime) { this->debounceTime = debounceTime; }

    void init() { pinMode(pin, INPUT_PULLUP); }
    State checkClick();
};