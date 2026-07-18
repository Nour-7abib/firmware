#include "PinTools.h"

#include "core/display.h"
#include "core/utils.h"

PinTools pinTools;

void PinTools::menu() {

    options.clear();

    options.push_back({"Pin 2 READ", []() { pinTools.pinRead(2); }});

    options.push_back({"Pin 2 HIGH", []() { pinTools.pinHigh(2); }});

    options.push_back({"Pin 2 LOW", []() { pinTools.pinLow(2); }});

    options.push_back({"Pin 4 READ", []() { pinTools.pinRead(4); }});

    options.push_back({"Pin 4 HIGH", []() { pinTools.pinHigh(4); }});

    options.push_back({"Pin 4 LOW", []() { pinTools.pinLow(4); }});

    loopOptions(options, MENU_TYPE_SUBMENU, "GPIO Tools");
}

void PinTools::pinRead(uint8_t pin) {

    pinMode(pin, INPUT);

    int state = digitalRead(pin);

    if (state) displayError("HIGH");
    else displayError("LOW");
}

void PinTools::pinHigh(uint8_t pin) {

    pinMode(pin, OUTPUT);

    digitalWrite(pin, HIGH);

    displayError("PIN HIGH");
}

void PinTools::pinLow(uint8_t pin) {

    pinMode(pin, OUTPUT);

    digitalWrite(pin, LOW);

    displayError("PIN LOW");
}
