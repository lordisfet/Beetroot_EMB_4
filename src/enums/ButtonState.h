#pragma once

enum ButtonState
{
    RELEASED,
    PRESSED
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == RELEASED) ? PRESSED : RELEASED;
}