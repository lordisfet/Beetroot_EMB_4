#pragma once

#include <Arduino.h>

enum LedState
{
    ON = HIGH,
    OFF = LOW
};

inline LedState operator!(LedState s)
{
    return (s == ON) ? OFF : ON;
}