#include <Arduino.h>

#include "button/State.h"
#include "button/debouncers/IDebouncer.h"

class InterruptWithoutDebounce : public IDebouncer
{
public:
    InterruptWithoutDebounce() = default;

    State update(State rawState, unsigned long currentTime) override
    {
        if (rawState == State::PRESSED)
        {
            clickCount++;
            return State::PRESSED;
        }
        return State::RELEASED;
    }
};