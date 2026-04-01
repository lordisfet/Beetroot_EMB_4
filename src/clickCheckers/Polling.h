#pragma once


#include "State.h"

class Polling
{
public:
    virtual State update(State rawState, unsigned long currentTime) {};
};
