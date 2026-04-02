#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/Checker.h"
#include "clickCheckers/Interrupt.h"
#include "clickCheckers/Polling.h"

class StateBasedDebounce : public Checker,
                           public Polling,
                           public Interrupt
{
public:
    StateBasedDebounce() { setName("StateBasedDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        if (!getIsPressed())
        {
            setIsPressed(true);
            setLastClickTime(currentTime);
        }
    }

    void update(State rawState, unsigned long currentTime) override
    {
        if (getIsPressed())
        {
            if (currentTime - getLastClickTime() > getDebounceTime())
            {
                if (rawState == PRESSED)
                {
                    incrementCount();
                }
                setIsPressed(false);
            }
        }
    }
};
