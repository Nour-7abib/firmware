#pragma once

class ArduinoManager {
public:
    ArduinoManager();

    void begin();
    void update();

    // Serial
    void openSerialMonitor();

    // GPIO
    void openPinTools();

    // I2C
    void openI2CTools();

private:
    bool _initialized;
};

extern ArduinoManager arduinoManager;
