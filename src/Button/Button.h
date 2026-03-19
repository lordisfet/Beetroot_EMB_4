#pragma once

#include <Arduino.h>
#include <State.h>

class Button
{
private:
    int8_t pin;
    State state;
    unsigned int debounceTime;

public:
    Button();
    Button(int8_t pin, State state = OFF, unsigned int debounceTime)
    {
        this->pin = pin;
        this->state = state;
        this->debounceTime = debounceTime;
    }
    ~Button();

    int8_t getPin() { return pin; }
    void setPin(int8_t pin) { this->pin = pin; }
    State getState() { return state; }
    void setState(State state) { this->state = state; }
    unsigned int getDebounceTime() { return debounceTime; }
    void setDebounceTime(unsigned int debounceTime) { this->debounceTime = debounceTime; }

    bool isClicked()
    {
        
    }
};