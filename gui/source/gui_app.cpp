#include "gui_app.hpp"

#include <filesystem>
#include <fstream>
#include "constants.hpp"
#include "utils.hpp"
//#include "app.hpp"

using namespace brls::literals;

bool run_gui_app() {
    bool versionsSame;

    std::filesystem::path gui_default{ CONFIG_PATH };
    gui_default.append(GUI_DEFAULT_FILE);
    std::filesystem::path cmd_default{ CONFIG_PATH };
    cmd_default.append(CMD_DEFAULT_FILE);

    if (!std::filesystem::exists(CONFIG_PATH)) std::filesystem::create_directory(CONFIG_PATH);
    if (std::filesystem::exists(cmd_default)) return true;  

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
    } else {
        //brls::Logger::debug("Successfully completed the init process");
    }

    brls::Application::createWindow("nxgui/title"_i18n);

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);
    brls::Application::registerXMLView("SwitchToCMD", SwitchToCMD::create);

    if (!versionsSame)
        brls::Application::registerXMLView("UpdaterTab", UpdaterTab::create);

    // If the program is sucessfull with the init process, it pushes the whole GUI
    if (versionsSame)
        brls::Application::pushActivity(new MainActivity());
    else
        brls::Application::pushActivity(new updateActivity());
    //brls::Logger::debug("Successfully completed the Push Activity function");

    // Main application loop
    while (brls::Application::mainLoop()) {
        if (std::filesystem::exists(cmd_default)) {
            try {
                std::filesystem::remove(gui_default);
            } catch (const std::filesystem::filesystem_error& e) {
                std::string str = "Filesystem error: " + std::string(e.what());
                brls::Logger::error(str);
            }
            //brls::Application::quit();

            std::fstream cmd_file;
            cmd_file.open(cmd_default.c_str(), std::ios::out|std::ios::app);
            cmd_file.close();

            brls::Application::quit();
        }
    }

    socketExit();

    if (std::filesystem::exists(cmd_default)) return true;

    // When the loop exits, it reports a successful exit
    return false;
}