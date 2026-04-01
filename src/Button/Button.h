#pragma once

#include <Arduino.h>

#include "State.h"
#include "clickCheckers/IChecker.h"

class Button
{
private:
    uint8_t _pin;
    // Для реалізації чітко на преривання для завдань 1 та 2 поідеї взагалі не потрібне поле State,
    // бо ми реагуємо на FALLING і просто потрібно змінити флаг, а потім в loop() перевіряти цей флаг
    // і якщо geyHasClicked() == true, то виводити лог і скидати флаг. Але для наступних обробників натискан ькнопки всеожно потрібне поле State.
    // І по факту воно повиннозберігати тільки теперешній фізичний стан кнопки, а не логічний, який залежить від обробника натискань.

public:
    Button(uint8_t pin, State state = RELEASED) : _pin(pin) { pinMode(_pin, INPUT_PULLUP); }
};