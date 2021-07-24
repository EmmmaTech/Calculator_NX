#include <borealis.hpp>
#include <nlohmann/json.hpp>

#include <calculatorTab.hpp>
#include <aboutTab.hpp>
#include <mainActivity.hpp>

using namespace brls::literals;

int main(int argc, char *argv[])
{
    //brls::Logger::setLogLevel(brls::LogLevel::DEBUG);
    
    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }
    brls::Application::createWindow("text/title"_i18n);
    brls::Application::setGlobalQuit(true);

    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    brls::Application::pushActivity(new MainActivity());

    while (brls::Application::mainLoop());
 
    return EXIT_SUCCESS;
}