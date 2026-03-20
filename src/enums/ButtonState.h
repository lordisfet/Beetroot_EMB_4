#pragma once

enum ButtonState
{
    UNCHANGED = 0,
    CHANGED = 1
};

inline ButtonState operator!(ButtonState bs)
{
    return (bs == UNCHANGED) ? CHANGED : UNCHANGED;
}