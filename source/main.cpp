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

/*truct MainActivity : public brls::Activity {
    CONTENT_FROM_XML_RES("activity/main.xml");
};*/

int main(int argc, char* argv[]) {
    std::vector<int> StoredInts{};
    MathCalculator calculator{StoredInts};
    std::string operation{};
    std::string App_Version = "v1.3.0 Developer GUI";

    //brls::Application::registerXMLView("CaptionedImage", CaptionedImage::create);
    //brls::Application::registerXMLView("RecyclingListTab", RecyclingListTab::create);
    //brls::Application::registerXMLView("ComponentsTab", ComponentsTab::create);

    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init("Calculator_NX " + App_Version)) {
        brls::Logger::error("Unable to init the Cakculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    }

    //brls::Application::pushActivity();

    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}
