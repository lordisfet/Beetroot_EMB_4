#pragma once

#include "State.h"

class Interrupt
{

public:
    virtual void onInterrupt(State rawState, unsigned long currentTime) = 0;
};
