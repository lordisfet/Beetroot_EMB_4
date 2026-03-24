#pragma once

#include "Led.h"
#include "enums/BlinkMode.h"

static constexpr unsigned int DEFAULT_BLINK_DURATION = 300;

class Blinker
{
private:
    Led &led;
    unsigned long blinkDurationMillis;
    unsigned long lastToggleTime;

public:
    Blinker(Led &led, unsigned long blinkDurationMillis = DEFAULT_BLINK_DURATION, unsigned long lastToggleTime = 0)
        : led(led), blinkDurationMillis(blinkDurationMillis), lastToggleTime(lastToggleTime) {}

    void blink();
};
