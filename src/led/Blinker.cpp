#include <MorseArduino.h>

#include "Blincker.h"
#include "BlinkMode.h"
#include "State.h"

void Blinker::nextBlinkMode()
{
    selectedMode = static_cast<BlinkMode>((selectedMode + 1) % COUNT);
    led.setState(OFF);
}

void Blinker::blink()
{
    static unsigned long currentTime = millis();
    switch (selectedMode)
    {
    case TURN_OFF:
        led.setState(OFF);
        break;

    case BLINKING:
        if (currentTime % blinkDurationMillis == 0)
        {
            led.setState(!led.getState());
        }
        break;

    case SOS:

        break;

    case TURN_ON:
        led.setState(ON);
        break;
    }
}