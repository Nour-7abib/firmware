#pragma once

class SerialMonitor {
public:
    void begin();
    void update();

    void open();
    void close();

private:
    bool _active = false;
};

extern SerialMonitor serialMonitor;
