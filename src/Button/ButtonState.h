#pragma once

#include <iostream>

enum ButtonState
{
    RELEASED,
    PRESSED
}

inline ButtonState operator!(ButtonState s)
{
    return (s == PRESED) ? RELEASED : PRESSED;
}