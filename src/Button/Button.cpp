#include <button/Button.h>

State Button::updateClick()
{
    static unsigned long lastClickTime;
    unsigned long currentTime = millis();
    bool currentState = digitalRead(pin);

    if (currentState != state && currentTime - lastClickTime > debounceTime)
    {
        state = !state;
        lastClickTime = currentTime;
    }

    // retunn !state because button uses inverted logic
    return !state;
}