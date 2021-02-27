#include "switchToGUI.hpp"

SwitchToCMD::SwitchToCMD() {
    this->inflateFromXMLRes("xml/tabs/switch_to_cmd.xml");

    BRLS_REGISTER_CLICK_BY_ID("main_button", this->onButtonClicked);
}

bool SwitchToCMD::onButtonClicked(brls::View* view) {
    brls::Application::quit();
    run_app();
}

brls::View* SwitchToCMD::create() {
    return new SwitchToCMD;
}