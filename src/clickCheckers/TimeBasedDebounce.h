#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/Checker.h"
#include "clickCheckers/Interrupt.h"
#include "clickCheckers/Polling.h"

class TimeBasedDebounce : public Checker, public Interrupt
{
public:
    TimeBasedDebounce() { setName("InterruptTimeBasedDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        if (currentTime - getLastClickTime() > getDebounceTime())
        {
            incrementCount();
            // setIsPressed(false) треба викликати вже в loop() після обробки флагу
            setIsPressed(true);
            setLastClickTime(currentTime);
        }
    }
};