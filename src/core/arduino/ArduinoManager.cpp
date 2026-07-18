#include "ArduinoManager.h"
#include "SerialMonitor.h"

ArduinoManager arduinoManager;

ArduinoManager::ArduinoManager() : _initialized(false) {}

void ArduinoManager::begin() {
    if (_initialized) return;

    serialMonitor.begin();

    _initialized = true;
}

void ArduinoManager::update() {
    if (!_initialized) return;

    serialMonitor.update();
}

void ArduinoManager::openSerialMonitor() { serialMonitor.open(); }

void ArduinoManager::openPinTools() {
    // سيتم إضافة GPIO لاحقاً
}

void ArduinoManager::openI2CTools() {
    // سيتم إضافة I2C لاحقاً
}
