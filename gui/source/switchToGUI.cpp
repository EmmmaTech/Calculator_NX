#include "switchToGUI.hpp"
#include <filesystem>
#include <fstream>
#include "constants.hpp"

SwitchToCMD::SwitchToCMD() {
    this->inflateFromXMLRes("xml/tabs/switch_to_cmd.xml");

    BRLS_REGISTER_CLICK_BY_ID("main_button", this->onButtonClicked);
}

bool SwitchToCMD::onButtonClicked(brls::View* view) {
    /*std::filesystem::path cmd_default{ CONFIG_PATH };
    cmd_default.append(CMD_DEFAULT_FILE);
    std::fstream cmd_file;

    cmd_file.open(cmd_default.c_str(), std::ios::out|std::ios::app);
    cmd_file.close();

    this->main_button->setText("Reopen the app to apply the changes.");*/

    guiAppRunning = false;
    cmdAppRunning = true;

    return true;
}

brls::View* SwitchToCMD::create() {
    return new SwitchToCMD;
}