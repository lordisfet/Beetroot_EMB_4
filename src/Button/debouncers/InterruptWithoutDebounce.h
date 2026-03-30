#include <Arduino.h>

#include "State.h"
#include "IDebouncer.h"

class InterruptWithoutDebounce : public IDebouncer
{
public:
    State update(State rawState, unsigned long currentTime) override
    {
        if (rawState == State::PRESSED)
        {
            return State::PRESSED;
        }
        return State::RELEASED;
    }
};