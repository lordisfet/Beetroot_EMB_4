#pragma once

#include "State.h"

class Polling
{
public:
    virtual void update(State rawState, unsigned long currentTime) = 0;
};
