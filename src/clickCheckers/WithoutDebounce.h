#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/abstract/InterruptChecker.h"

class WithoutDebounce : public InterruptChecker
{
public:
    WithoutDebounce() { setName("InterruptWithoutDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        incrementCount();
        setIsPressed(true);
    }
};