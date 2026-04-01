#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/abstract/Checker.h"

// TODO: split IChecker to interrupting and polling
class InterruptChecker : public Checker
{
public:
    virtual void onInterrupt(State rawState, unsigned long currentTime) {}
};
