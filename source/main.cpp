#include <borealis.hpp>

#include <vector>
#include <stdlib.h>

#include <calculator.hpp>

namespace i18n = brls::i18n;
using namespace i18n::literals;

std::vector<std::string> expressions {
    "3*3+3-3/3",
    "3*(3+3)-3/3",
    "3*3+(3-3)/3",
    "3*3+3-(3/3)",
    "(1+1)-1*1/1",
    "1+(1-1)*1/1",
    "1+1-1*1/1",
    "1+1-1*(1/1)",
};

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

    brls::Label *label = new brls::Label(brls::LabelStyle::REGULAR, "Result: N/A", true);
    list->addView(label);

    brls::Button *button = new brls::Button();
    button->setLabel("A very, very cool button");
    button->setWidth(25);
    button->setHeight(30);
    button->getClickEvent()->subscribe([&](brls::View *view)
    {
        std::string &exp = expressions[rand() % expressions.size()];
        button->setLabel("Set text pls");

        auto res = Calculator::getInstance().evaluateExpression(exp);
        label->setText("Result: " + std::to_string(res));
    });
    list->addView(button);

    rootFrame->addTab("Home", list);
    
    // Add the TabFrame (root frame) to the view stack
    brls::Application::pushView(rootFrame);

    // Application loop
    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}