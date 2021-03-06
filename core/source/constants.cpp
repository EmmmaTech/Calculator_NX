#include "constants.hpp"

namespace AppsRunning {
    
    bool guiAppRunning;
    bool cmdAppRunning;

    void setGUIApp(bool newValue) {
        guiAppRunning = newValue;
    }
    bool getGUIApp() {
        return guiAppRunning;
    }

    void setCMDApp(bool newValue) {
        cmdAppRunning = newValue;
    }
    bool getCMDApp() {
        return cmdAppRunning;
    }

}