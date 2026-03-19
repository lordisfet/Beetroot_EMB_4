#include <button/Button.h>

// For active button`s state I use HIGH level for synhronization with led state
// and using one class State for define component status
// I guees to use !state for returning when button presed, but this look strange
State Button::updateClick()
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