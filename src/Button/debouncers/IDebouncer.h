#pragma once

#include <Arduino.h>

#include "button/State.h"

class IDebouncer
{
public:
    unsigned int clickCount = 0;

    virtual State update(State rawState, unsigned long currentTime) = 0;
    virtual unsigned int getCount() const { return clickCount; }
};
