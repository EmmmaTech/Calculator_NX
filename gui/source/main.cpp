// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>

// Include additional libraries for the Switch program
#include <switch.h>
#include <borealis.hpp>
#include "calculatorTab.hpp"
#include "mainActivity.hpp"
#include "aboutTab.hpp"
#include "updateActivity.hpp"
#include "updaterTab.hpp"
#include <filesystem>
#include <fstream>
#include "constants.hpp"
#include "download.hpp"

using namespace brls::literals;

int main(int argc, char* argv[]) {
    bool versionsSame;

    if (!std::filesystem::exists(CONFIG_PATH)) std::filesystem::create_directory(CONFIG_PATH);
    if (!std::filesystem::exists(DOWNLOAD_PATH)) std::filesystem::create_directory(DOWNLOAD_PATH);

    socketInitializeDefault();

    // Set up the logger 
    brls::Logger::setLogLevel(brls::LogLevel::INFO);

    std::string version_from_api = getLatestTag(std::string(API_URL));
    std::string currentVersion = std::string(APP_VERSION);
    versionsSame = version_from_api == currentVersion;

    // Init the app and i18n
    if (!brls::Application::init()) {
        // If the program fails init process, it reports this and stops
        brls::Logger::error("Unable to init the Calculator_NX gui. Please report this to EmreTech");
        return false;
    }

    brls::Application::createWindow("nxgui/title"_i18n);

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    if (!versionsSame)
        brls::Application::registerXMLView("UpdaterTab", UpdaterTab::create);

    // If the program is sucessfull with the init process, it pushes the whole GUI
    if (versionsSame)
        brls::Application::pushActivity(new MainActivity());
    else
        brls::Application::pushActivity(new updateActivity());

    // Main application loop
    while (brls::Application::mainLoop());

    socketExit();

    // When the loop exits, it reports a successful exit
    return EXIT_SUCCESS;
}
