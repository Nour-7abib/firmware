#include "ArduinoManager.h"

ArduinoManager arduinoManager;

ArduinoManager::ArduinoManager() : _unoSerial(2), _initialized(false) {}

void ArduinoManager::begin() {
    if (_initialized) return;

    // CYD RX = IO27
    // CYD TX = IO22
    _unoSerial.begin(115200, SERIAL_8N1, 27, 22);

    _initialized = true;
}

void ArduinoManager::update() {
    if (!_initialized) return;
}

String ArduinoManager::sendCommand(const String &command, uint32_t timeout) {
    if (!_initialized) { begin(); }

    // امسح أي بيانات قديمة
    while (_unoSerial.available()) { _unoSerial.read(); }

    _unoSerial.println(command);

    String response;
    uint32_t started = millis();

    while (millis() - started < timeout) {
        while (_unoSerial.available()) {
            char c = (char)_unoSerial.read();

            if (c == '\r') continue;

            if (c == '\n') {
                response.trim();

                if (response.length() > 0) { return response; }
            } else {
                response += c;
            }
        }

        delay(1);
    }

    response.trim();

    if (response.length() == 0) { return "NO_RESPONSE"; }

    return response;
}

bool ArduinoManager::detectUno() { return sendCommand("PING") == "PONG"; }

String ArduinoManager::readRfid() { return sendCommand("RFID", 3000); }

void ArduinoManager::openSerialMonitor() {
    // لاحقًا
}

void ArduinoManager::openPinTools() {
    // لاحقًا
}

void ArduinoManager::openI2CTools() {
    // لاحقًا
}
