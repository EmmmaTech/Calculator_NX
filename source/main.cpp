// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <calculator.hpp>

// Include additional libraries for the Switch program
#include <switch.h>
#include <borealis.hpp>
#include "calculatorTab.hpp"
#include "mainActivity.hpp"

int main(int argc, char* argv[]) {
    std::vector<int> StoredInts{};
    MathCalculator calculator{StoredInts};
    std::string operation{};

    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);

    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init("Calculator_NX")) {
        brls::Logger::error("Unable to init the Cakculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    }

    brls::Application::pushActivity(new MainActivity());

    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}
