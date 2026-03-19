// #include <Morse.h>

#include "Blinker.h"
#include "enums/LedState.h"

void Blinker::nextBlinkMode()
{
    selectedMode = static_cast<BlinkMode>((selectedMode + 1) % COUNT);
    // led.setState(OFF);
}

void Blinker::blink()
{
    static unsigned long currentTime = millis();
    switch (selectedMode)
    {
    case TURN_OFF:
        led.setState(OFF);
        Serial.println("Blink mode: " + (String)selectedMode);
        break;

    case BLINKING:
        static unsigned long lastToggleTime = 0;
        if (currentTime - lastToggleTime >= blinkDurationMillis)
        {
            lastToggleTime = currentTime;
            led.setState(!led.getState());
        }

        Serial.println("Blink mode: " + (String)selectedMode + (String)millis());
        break;

        // case SOS:

        //     break;

    case TURN_ON:
        led.setState(ON);
        Serial.println("Blink mode: " + (String)selectedMode);
        break;
    }
}