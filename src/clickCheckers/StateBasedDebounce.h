#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/Checker.h"
#include "clickCheckers/Interrupt.h"
#include "clickCheckers/Polling.h"

class StateBasedDebounce : public Checker, public Polling, public Interrupt
{
public:
    StateBasedDebounce() { setName("StateBasedDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        setIsPressed(rawState == PRESSED);
        setLastClickTime(currentTime);
    }

    State update(State rawState, unsigned long currentTime) override
    {
        if (getIsPressed() && rawState == PRESSED && currentTime - getLastClickTime() > getDebounceTime())
        {
            incrementCount();
            setIsPressed(false);
        }
        return rawState;
    }
};
