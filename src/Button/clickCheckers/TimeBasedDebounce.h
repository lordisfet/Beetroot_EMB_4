#include <Arduino.h>

#include "button/State.h"
#include "button/clickCheckers/IDebouncer.h"

// Debounce with time based logic
class TimeBasedDebounce : public IDebouncer
{
private:
    unsigned int _lastClickTime = 0;
    unsigned int _debounceTime = 100;

public:
    TimeBasedDebounce() { setName("TimeBasedDebounce"); };

    State update(State rawState, unsigned long currentTime) override
    {
        if (currentTime - _lastClickTime > _debounceTime)
        {
            incrementCount();
            _lastClickTime = currentTime;
            return PRESSED;
        }
        return RELEASED;
    }
};