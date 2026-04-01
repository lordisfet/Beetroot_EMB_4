#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/abstract/Checker.h"

// TODO: split IChecker to interrupting and polling
class PollingChecker : public Checker
{
public:

    virtual State update(State rawState, unsigned long currentTime) = 0;
};
