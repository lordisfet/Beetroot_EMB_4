#include <Arduino.h>

#include "button/State.h"
#include "button/debouncers/IDebouncer.h"

class InterruptWithoutDebounce : public IDebouncer
{
public:
    InterruptWithoutDebounce() {};

    State update(State rawState, unsigned long currentTime) override
    {
        clickCount++;
        return rawState == State::PRESSED ? State::PRESSED : State::RELEASED;
    }
};