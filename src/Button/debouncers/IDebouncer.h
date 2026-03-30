#include <Arduino.h>

#include "State.h"

class IDebouncer
{
public:
    unsigned int clickCount = 0;

    virtual State update(State rawState, unsigned long currentTime);
    virtual unsigned int getCount() const { return clickCount; }
};
