#include <borealis.hpp>

namespace i18n = brls::i18n;
using namespace i18n::literals;

int main(int argc, char *argv[])
{
    i18n::loadTranslations();
    if (!brls::Application::init("Calculator_NX Rewrite"))
    {
        brls::Logger::error("Failed to init borealis application. Quitting...");
        return EXIT_FAILURE;
    }

    brls::TabFrame *rootFrame = new brls::TabFrame();
    rootFrame->setTitle("Calculator_NX Rewrite");
    rootFrame->setIcon(BOREALIS_ASSET("icon/Calculator_NX_Icon_Alt.jpg"));

    brls::List *list = new brls::List();

    brls::Button *button = new brls::Button();
    button->setLabel("A very, very cool button");
    button->setWidth(25);
    button->setHeight(30);
    button->getClickEvent()->subscribe([](brls::View *view)
    {
        brls::Application::notify("I'm not russian idiots");
    });
    list->addView(button);

    rootFrame->addTab("Home", list);
    
    // Add the TabFrame (root frame) to the view stack
    brls::Application::pushView(rootFrame);

    // Application loop
    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}