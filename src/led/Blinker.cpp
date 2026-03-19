// #include <Morse.h>

#include "Blinker.h"
#include "enums/LedState.h"

void Blinker::nextBlinkMode()
{
    selectedMode = static_cast<BlinkMode>((static_cast<int>(selectedMode) + 1) % COUNT);
    led.setState(OFF);
}

void Blinker::blink()
{
    unsigned long currentTime = millis();
    switch (selectedMode)
    {
    case TURN_OFF:
    {
        led.setState(OFF);
        break;
    }

    case BLINKING:
    {
        static unsigned long lastToggleTime = 0;
        if (currentTime - lastToggleTime >= blinkDurationMillis)
        {
            lastToggleTime = currentTime;
            led.setState(!led.getState());
        }

        break;
    }

        // case SOS:

        //     break;

    case TURN_ON:
    {
        led.setState(ON);
        break;
    }
    }
}