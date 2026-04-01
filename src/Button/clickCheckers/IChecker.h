#pragma once

#include <Arduino.h>

#include "button/State.h"

class IChecker
{
private:
    String _name;
    unsigned int _clickCount = 0;
    unsigned int _lastClickTime = 0;
    // Для цього завдання це поле не потрібне, але додав. Може потім буду юзати цей клас в наступних роботах
    volatile bool _isPressed = false;

public:
    unsigned int getCount() const { return _clickCount; }
    unsigned int getLastClickTime() const { return _lastClickTime; }
    String getName() const { return _name; }
    bool getIsPressed() const { return _isPressed; }

    void setLastClickTime(unsigned int time) { _lastClickTime = time; }
    void setName(String name) { _name = name; }
    void setIsPressed(bool isPressed) { _isPressed = isPressed; }

    void incrementCount() { _clickCount++; }

    virtual void onInterrupt(State rawState, unsigned long currentTime) {}
    virtual State update(State rawState, unsigned long currentTime) = 0;
};
