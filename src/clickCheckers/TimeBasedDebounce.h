#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/abstract/InterruptChecker.h"

class TimeBasedDebounce : public InterruptChecker
{
private:
    unsigned int _lastClickTime = 0;
    unsigned int _debounceTime = 100;

public:
    TimeBasedDebounce() { setName("InterruptTimeBasedDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        if (currentTime - _lastClickTime > _debounceTime)
        {
            incrementCount();
            setIsPressed(true);
            _lastClickTime = currentTime;
        }
    }
};