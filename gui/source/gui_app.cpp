#include "gui_app.hpp"

using namespace brls::literals;

void run_gui_app() {
    // Set up the logger 
    brls::Logger::setLogLevel(brls::LogLevel::INFO);

    // Init the app and i18n
    if (!brls::Application::init()) {
        // If the program fails init process, it reports this and stops
        brls::Logger::error("Unable to init the Calculator_NX gui. Please report this to EmreTech");
        return;
    } else {
        //brls::Logger::debug("Successfully completed the init process");
    }

    brls::Application::createWindow("nxgui/title"_i18n);

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("SwitchToCMD", SwitchToCMD::create);

    // If the program is sucessfull with the init process, it pushes the whole GUI
    brls::Application::pushActivity(new MainActivity());
    //brls::Logger::debug("Successfully completed the Push Activity function");

    // Main application loop
    while (brls::Application::mainLoop());

    // When the loop exits, it reports a successful exit
    return;
}