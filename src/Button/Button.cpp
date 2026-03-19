#include "Button.h"
#include "ButtonState.h"

ButtonState Button::updateClick()
{
    static unsigned long lastClickTime;
    unsigned long currentTime = millis();
    bool currentState = digitalRead(pin);

    if (currentState != state && currentTime - lastClickTime > debounceTime)
    {
        state = !state;
        lastClickTime = currentTime;
        return state;
    }

    return !state;
}