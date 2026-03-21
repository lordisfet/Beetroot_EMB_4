#include "Button.h"

void IRAM_ATTR Button::isrHandler()
{
    unsigned long currentTime = millis();

    if (currentTime - lastClickTime > debounceTime)
    {
        if (digitalRead(pin) == LOW)
        {
            state = !state;
            lastClickTime = currentTime;
        }
    }
}

void IRAM_ATTR Button::isrWrapped(void *arg)
{
    if (arg != NULL)
    {
        Button *button = static_cast<Button *>(arg);
        button->isrHandler();
    }
}

void Button::init()
{
    pinMode(pin, INPUT_PULLUP);
    attachInterruptArg(pin, isrWrapped, this, FALLING);
}