// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

// Include additional libraries for the Switch program
#include <switch.h>
#include <borealis.hpp>

namespace CalculatorGUI {

    struct Init {

        static void initGUI() {
            brls::Application::init("Calculator_NX");
        }
        
    };

}