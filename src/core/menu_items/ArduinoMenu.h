#ifndef __ARDUINO_MENU_H__
#define __ARDUINO_MENU_H__

#include "MenuItemInterface.h"

class ArduinoMenu : public MenuItemInterface {

public:
    ArduinoMenu() : MenuItemInterface("Arduino") {}

    void optionsMenu(void);
    void drawIcon(float scale);

    bool hasTheme() { return false; }
    String themePath() { return ""; }
};

#endif
