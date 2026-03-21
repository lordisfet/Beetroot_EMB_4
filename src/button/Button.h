#pragma once

#include <Arduino.h>

enum ButtonState
{
    UNCHANGED = 0,
    CHANGED = 1
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == UNCHANGED) ? CHANGED : UNCHANGED;
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
    Button(int8_t pin, unsigned int debounceTime = DEFAULT_DEBOUNCE_DURATION, ButtonState state = UNCHANGED)
        : pin(pin), debounceTime(debounceTime), state(state) {}

    ButtonState getState() { return state; }
    void setState(ButtonState s) { state = s; }

    void init();
    void IRAM_ATTR isrHandler();
    void static IRAM_ATTR isrWrapped(void *arg);
    ButtonState updateClick();
};