#include <borealis.hpp>

#include <calculatorTab.hpp>
#include <mainActivity.hpp>

using namespace brls::literals;

int main(int argc, char *argv[])
{
    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }
    brls::Application::createWindow("Calculator_NX rewrite");
    brls::Application::setGlobalQuit(true);

    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::pushActivity(new MainActivity());

    while (brls::Application::mainLoop());
 
    return EXIT_SUCCESS;
}