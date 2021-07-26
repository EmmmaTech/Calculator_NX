#include <borealis.hpp>
#include <switch.h>

#include <filesystem>

#include <constants.hpp>
#include <calculatorTab.hpp>
#include <aboutTab.hpp>
#include <mainActivity.hpp>

using namespace brls::literals;

int main(int argc, char *argv[])
{
    //brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    // File-related checks before booting

    if (!std::filesystem::exists(PATH_1))
    {
        std::filesystem::create_directory(CALCULATOR_NX_PATH);
        std::filesystem::copy_file(PATH_2, PATH_1);
        envSetNextLoad(PATH_1, ("\"" + std::string(PATH_1) + "\"").c_str());
    }

    if (std::filesystem::exists(PATH_2))
        std::filesystem::remove(PATH_2);

    if (!std::filesystem::exists(CONFIG_PATH))
        std::filesystem::create_directories(CONFIG_PATH);
    
    // Init the borealis application

    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }
    brls::Application::createWindow("text/title"_i18n);
    brls::Application::setGlobalQuit(true);

    // Register XML views and push activity

    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    brls::Application::pushActivity(new MainActivity());

    // Start the main application loop

    while (brls::Application::mainLoop());
 
    return EXIT_SUCCESS;
}