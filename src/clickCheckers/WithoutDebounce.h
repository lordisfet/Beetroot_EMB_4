#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/Checker.h"
#include "clickCheckers/Interrupt.h"
#include "clickCheckers/Polling.h"

class WithoutDebounce : public Checker, public Interrupt
{
public:
    WithoutDebounce() { setName("InterruptWithoutDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        incrementCount();
        setIsPressed(true);
    }
};