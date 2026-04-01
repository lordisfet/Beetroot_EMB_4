#include <Arduino.h>

#include "button/State.h"
#include "button/clickCheckers/IDebouncer.h"

class WithoutDebounce : public IDebouncer
{
public:
    WithoutDebounce() { setName("InterrptWithoutDebounce"); };

    State update(State rawState, unsigned long currentTime) override
    {
        incrementCount();
        return rawState == PRESSED ? PRESSED : RELEASED;
    }
};