#pragma once

#include <Arduino.h>

class PinTools {
public:
    void menu();

private:
    void pinRead(uint8_t pin);
    void pinHigh(uint8_t pin);
    void pinLow(uint8_t pin);
};

extern PinTools pinTools;
