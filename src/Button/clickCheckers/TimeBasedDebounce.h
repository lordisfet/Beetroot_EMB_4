#include <Arduino.h>

#include "button/State.h"
#include "button/clickCheckers/IChecker.h"

class TimeBasedDebounce : public IChecker
{
private:
    unsigned int _lastClickTime = 0;
    unsigned int _debounceTime = 100;

public:
    TimeBasedDebounce() { setName("TimeBasedDebounce"); }

    void onInterrupt(State rawState, unsigned long currentTime) override
    {
        if (currentTime - _lastClickTime > _debounceTime)
        {
            incrementCount();
            setIsPressed(true);
            _lastClickTime = currentTime;
        }
    }
};