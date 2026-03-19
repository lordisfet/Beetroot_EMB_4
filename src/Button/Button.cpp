#include <button/Button.h>

State Button::checkClick()
{
    static unsigned long lastClickTime;
    unsigned long currentTime = millis();
    bool currentState = digitalRead(pin);

    if (state != currentState)
    {
        lastClickTime = currentTime;
    }
    Add if (lastClickTime + debounceTime > currentTime)
    {
        if (state != currentState)
        {
            state = !state;
        }
    }
}