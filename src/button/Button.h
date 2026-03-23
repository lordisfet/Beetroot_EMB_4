#pragma once

#include <Arduino.h>

enum ButtonState
{
    UNACTIVE = 0,
    ACTIVE = 1
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == UNACTIVE) ? ACTIVE : UNACTIVE;
}

static constexpr unsigned int DEFAULT_DEBOUNCE_DURATION = 50;

class Button
{
private:
    const int8_t pin;
    unsigned int debounceTime;
    volatile ButtonState state;
    unsigned long lastClickTime = 0;

public:
    Button(int8_t pin, unsigned int debounceTime = DEFAULT_DEBOUNCE_DURATION, ButtonState state = UNACTIVE)
        : pin(pin), debounceTime(debounceTime), state(state) {}

    ButtonState getState() { return state; }
    void setState(ButtonState s) { state = s; }

    void init();
    void IRAM_ATTR isrHandler();
    void static IRAM_ATTR isrWrapped(void *arg);
};