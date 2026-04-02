#pragma once

#include "clickCheckers/Checker.h"
#include "clickCheckers/Polling.h"

class PollingDebounce : public Checker, public Polling
{
private:
    enum class InternalState
    {
        IDLE,
        DEBOUNCE,
        PRESSED
    };

    InternalState _state = InternalState::IDLE;

public:
    PollingDebounce() { setName("PollingDebounce"); }

    void update(State rawState, unsigned long currentTime) override
    {
        switch (_state)
        {
        case InternalState::IDLE:
            if (rawState == PRESSED)
            {
                _state = InternalState::DEBOUNCE;
                setLastClickTime(currentTime);
            }
            break;
        case InternalState::DEBOUNCE:
            if (currentTime - getLastClickTime() > getDebounceTime())
            {
                if (rawState == PRESSED)
                {
                    incrementCount();
                    _state = InternalState::PRESSED;
                }
                else
                {
                    _state = InternalState::IDLE;
                }
            }
            break;
        case InternalState::PRESSED:
            if (rawState == RELEASED)
            {
                _state = InternalState::IDLE;
            }
            break;
        default:
            break;
        }
    }
};
