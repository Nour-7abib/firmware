#include "ArduinoMenu.h"

#include "core/arduino/ArduinoManager.h"
#include "core/arduino/PinTools.h"
#include "core/display.h"
#include "core/utils.h"

void ArduinoMenu::optionsMenu() {

    options.clear();

    options.push_back({"GPIO Tools", []() { pinTools.menu(); }});

    options.push_back({"UART Test", []() {
                           Serial.println("Arduino UART OK");
                           displayError("UART OK");
                       }});

    addOptionToMainMenu();

    loopOptions(options, MENU_TYPE_SUBMENU, "Arduino");
}

void ArduinoMenu::drawIcon(float scale) {
    clearIconArea();

    int radius = scale * 7;

    tft.drawCircle(iconCenterX, iconCenterY, radius * 3, bruceConfig.priColor);

    tft.fillCircle(iconCenterX - radius, iconCenterY, radius, bruceConfig.priColor);

    tft.fillCircle(iconCenterX + radius, iconCenterY, radius, bruceConfig.priColor);

    tft.drawLine(
        iconCenterX - radius * 2,
        iconCenterY + radius * 2,
        iconCenterX + radius * 2,
        iconCenterY + radius * 2,
        bruceConfig.priColor
    );
}
