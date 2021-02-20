// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include "calculator.hpp"

// Include additional libraries for the Switch program
#ifdef __SWITCH__
#include <switch.h>
#endif

#include <borealis.hpp>
#include "calculatorTab.hpp"
#include "mainActivity.hpp"
#include "aboutTab.hpp"

// The program is working, but in a broken state

using namespace brls::literals;

int main(int argc, char* argv[]) {
    // Set up the logger 
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    // Init the app and i18n
    if (!brls::Application::init()) {
        // If the program fails init process, it reports this and stops
        brls::Logger::error("Unable to init the Calculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    } else {
        brls::Logger::debug("Successfully completed the init process");
    }

    brls::Application::createWindow("nxgui/title"_i18n);

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    // If the program is sucessfull with the init process, it pushes the whole GUI
    brls::Application::pushActivity(new MainActivity());
    brls::Logger::debug("Successfully completed the Push Activity function");

    // Main application loop
    while (brls::Application::mainLoop())
        ;

    // When the loop exits, it reports a successful exit
    return EXIT_SUCCESS;
}
