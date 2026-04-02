#pragma once

#include <Arduino.h>

#include "State.h"

class Checker
{
private:
    String _name;
    volatile unsigned int _clickCount = 0;
    unsigned int _lastClickCount = 0;
    volatile unsigned int _lastClickTime = 0;
    unsigned int _debounceTime = 50;
    volatile bool _isPressed = false;

public:
    String getName() const { return _name; }
    unsigned int getClickCount() const { return _clickCount; }
    unsigned int getLastClickCount() const { return _lastClickCount; }
    unsigned int getLastClickTime() const { return _lastClickTime; }
    unsigned int getDebounceTime() const { return _debounceTime; }
    bool getIsPressed() const { return _isPressed; }

    void setName(String name) { _name = name; }
    void setLastClickCount(unsigned int lastClickCount) { _lastClickCount = lastClickCount; }
    void setLastClickTime(unsigned int lastClickTime) { _lastClickTime = lastClickTime; }
    void setIsPressed(bool isPressed) { _isPressed = isPressed; }

    void incrementCount() { _clickCount++; }
};
