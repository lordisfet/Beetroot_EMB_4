#include "Button.h"

ButtonState Button::updateClick()
{
    static unsigned long lastClickTime = 0;
    static ButtonState previousState = RELEASED;
    unsigned long currentTime = millis();
    ButtonState currentState = static_cast<ButtonState>(getState());

    if (currentState != previousState && currentTime - lastClickTime > debounceTime)
    {
        previousState = currentState;
        lastClickTime = currentTime;

        if (currentState == PRESSED)
        {
            return PRESSED;
        }
    }

    return RELEASED;
}