// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
//#include "calculator.hpp"

// Include additional libraries for the Switch program
#include <switch.h>
#include <borealis.hpp>
#include "calculatorTab.hpp"
#include "mainActivity.hpp"
#include "aboutTab.hpp"

// The program is currently not working at the moment

int main(int argc, char* argv[]) {
    // Define important variables for the actual calculation
    std::vector<int> StoredInts{};
    //MathCalculator calculator{StoredInts}; 
    std::string operation{};

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    // Set everything up for the borealis GUI
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init("Calculator_NX")) {
        // If the program fails init process, it reports this and stops
        brls::Logger::error("Unable to init the Cakculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    }

    // If the program is sucessfull with the init process, it pushes the whole GUI
    brls::Application::pushActivity(new MainActivity());

    // Main application loop
    while (brls::Application::mainLoop());

    // When the loop exits, it reports a successful exit
    return EXIT_SUCCESS;
}
