#pragma once

#include <Arduino.h>

#include "State.h"

// TODO: split IChecker to interrupting and polling
class Checker
{
private:
    String _name;
    volatile unsigned int _clickCount = 0;
    unsigned int _lastClickCount = 0;
    unsigned int _lastClickTime = 0;
    // Для цього завдання це поле не потрібне, але додав. Може потім буду юзати цей клас в наступних роботах
    volatile bool _isPressed = false;

public:
    unsigned int getClickCount() const { return _clickCount; }
    unsigned int getLastClickTime() const { return _lastClickCount; }
    unsigned int getLastClickTime() const { return _lastClickTime; }
    String getName() const { return _name; }
    bool getIsPressed() const { return _isPressed; }

    void setName(String name) { _name = name; }
    void setIsPressed(bool isPressed) { _isPressed = isPressed; }
    void setLastClickTime(unsigned int lastClickTime) { _lastClickCount = lastClickTime; }
    void setLastClickTime(unsigned int lastClickTime) { _lastClickTime = lastClickTime; }

    void incrementCount() { _clickCount++; }
};
