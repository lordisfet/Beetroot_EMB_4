#pragma once

#include <Arduino.h>

#include "button/State.h"

class IDebouncer
{
private:
    unsigned int _clickCount = 0;
    unsigned int _lastClickTime = 0;
    String _name;

public:
    unsigned int getCount() const { return _clickCount; }
    unsigned int getLastClickTime() const { return _lastClickTime; }
    String getName() const { return _name; }

    void setLastClickTime(unsigned int time) { _lastClickTime = time; }
    void setName(String name) { _name = name; }

    void incrementCount() { _clickCount++; }

    virtual State update(State rawState, unsigned long currentTime) = 0;
};
