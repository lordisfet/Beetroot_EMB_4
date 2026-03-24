#include "Blinker.h"
#include "enums/LedState.h"

void Blinker::blink()
{
    unsigned long currentTime = millis();
    if (currentTime - lastToggleTime > blinkDurationMillis)
    {
        led.setState(!led.getState());
        lastToggleTime = currentTime;
    }
}