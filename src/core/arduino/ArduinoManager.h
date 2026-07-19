#pragma once

#include <Arduino.h>

class ArduinoManager {
public:
    ArduinoManager();

    void begin();
    void update();

    String sendCommand(const String &command, uint32_t timeout = 1500);

    bool detectUno();
    String readRfid();

    void openSerialMonitor();
    void openPinTools();
    void openI2CTools();

private:
    HardwareSerial _unoSerial;
    bool _initialized;
};

extern ArduinoManager arduinoManager;
