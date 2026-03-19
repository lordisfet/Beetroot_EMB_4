#pragma once

enum ButtonState
{
    RELEASED = 0,
    PRESSED = 1
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == RELEASED) ? PRESSED : RELEASED;
}