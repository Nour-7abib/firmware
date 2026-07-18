#include "SerialMonitor.h"
#include <Arduino.h>

SerialMonitor serialMonitor;

void SerialMonitor::begin() { Serial.begin(115200); }

void SerialMonitor::update() {
    if (!_active) return;

    while (Serial.available()) {
        char c = Serial.read();
        Serial.write(c);
    }
}

void SerialMonitor::open() {
    _active = true;
    Serial.println("Serial Monitor Started");
}

void SerialMonitor::close() {
    _active = false;
    Serial.println("Serial Monitor Stopped");
}
