#pragma once

#include "Led.h"
#include "enums/BlinkMode.h"

static constexpr unsigned int DEFAULT_BLINK_DURATION = 100;

class Blinker
{
private:
    Led led;
    unsigned long blinkDurationMillis;
    BlinkMode selectedMode;

public:
    Blinker(Led led, unsigned long blinkDurationMillis = DEFAULT_BLINK_DURATION, BlinkMode selectedMode = TURN_OFF)
        : led(led), blinkDurationMillis(blinkDurationMillis), selectedMode(selectedMode) {};

    void nextBlinkMode();
    void blink();
};
