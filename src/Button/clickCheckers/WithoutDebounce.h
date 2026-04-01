#include <Arduino.h>

#include "button/State.h"
#include "button/clickCheckers/IChecker.h"

class WithoutDebounce : public IChecker
{
public:
    WithoutDebounce() { setName("InterrptWithoutDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        incrementCount();
        setIsPressed(true);
    }
};