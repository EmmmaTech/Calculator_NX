#include <borealis.hpp>
#include <switch.h>

#include <fs.hpp>
#include <constants.hpp>
#include <mainActivity.hpp>

using namespace brls::literals;

int main(int argc, char *argv[])
{
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    // File-related checks before booting

    if (!std::filesystem::exists(PATH_1))
    {
        std::filesystem::create_directory(CALCULATOR_NX_PATH);
        fs::copyFile(PATH_1, PATH_2);
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

    // Push activity

    brls::Application::pushActivity(new MainActivity());

    // Start the main application loop

    while (brls::Application::mainLoop());
 
    return EXIT_SUCCESS;
}