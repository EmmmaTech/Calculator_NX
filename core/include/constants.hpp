#pragma once

#define ROOT_PATH "/"
#define CONFIG_PATH "/config/Calculator_NX/"
#define GUI_DEFAULT_FILE "gui_default.txt"
#define CMD_DEFAULT_FILE "cmd_default.txt"

namespace AppsRunning {
    void setGUIApp(bool newValue);
    bool getGUIApp();

    void setCMDApp(bool newValue);
    bool getCMDApp();
}