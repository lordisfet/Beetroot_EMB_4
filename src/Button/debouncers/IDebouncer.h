#include <Arduino.h>

#include "State.h"

class IDebouncer
{
public:
    virtual State update(State rawState, unsigned long currentTime);
};
