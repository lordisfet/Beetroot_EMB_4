#pragma once

enum ButtonState
{
    PRESSED = 0,
    RELEASED = 1
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == RELEASED) ? PRESSED : RELEASED;
}