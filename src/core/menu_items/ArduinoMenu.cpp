#include "ArduinoMenu.h"

#include "core/arduino/ArduinoManager.h"
#include "core/arduino/PinTools.h"
#include "core/display.h"
#include "core/utils.h"

void ArduinoMenu::optionsMenu() {

    options.clear();

    options.push_back({"Detect UNO", []() {
                           if (arduinoManager.detectUno()) {
                               displayError("UNO CONNECTED");
                           } else {
                               displayError("UNO NOT FOUND");
                           }
                       }});

    options.push_back({"Read RFID", []() {
                           String result = arduinoManager.readRfid();

                           displayError(result);
                       }});

    options.push_back({"GPIO Tools", []() {
                           pinTools.menu();
                       }});

    addOptionToMainMenu();

    loopOptions(options, MENU_TYPE_SUBMENU, "Arduino");
}
