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
#include <switch.h>
#include <borealis.hpp>

/*char* SoftwareKeyboard(Result rc, const char * guideText) {
    SwkbdConfig kbd;
    char * tmpoutstr;
            
    rc = swkbdCreate(&kbd, 0);
    //printf("swkbdCreate(): 0x%x\n", rc);
    if (R_SUCCEEDED(rc)) {
        // Select a Preset to use, if any.
        swkbdConfigMakePresetDefault(&kbd);

        // Optional, set any text if you want (see swkbd.h).
        //swkbdConfigSetOkButtonText(&kbd, "Submit");
        //swkbdConfigSetLeftOptionalSymbolKey(&kbd, "a");
        //swkbdConfigSetRightOptionalSymbolKey(&kbd, "b");
        //swkbdConfigSetHeaderText(&kbd, "Header");
        //swkbdConfigSetSubText(&kbd, "Sub");
        swkbdConfigSetGuideText(&kbd, guideText);

        //Optional, can be removed if not using TextCheck.

        // Set the initial string if you want.
        //swkbdConfigSetInitialText(&kbd, "Initial");

        // You can also use swkbdConfigSet*() funcs if you want.

        //printf("Running swkbdShow...\n");
        rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));
        //printf("swkbdShow(): 0x%x\n", rc);

        if (R_SUCCEEDED(rc)) {
                    printf("out str: %s\n", tmpoutstr);
        }
        swkbdClose(&kbd);
    }

    return tmpoutstr;
}*/

int main(int argc, char* argv[]) {
    std::vector<int> StoredInts{};
    MathCalculator calculator{StoredInts};
    std::string operation{};
    std::string App_Version = "v1.3.0 Developer GUI";

    auto Frame = brls::AppletFrame::AppletFrame();
    Frame.setTitle("Calculator_NX " + App_Version);

    if (!brls::Application::init("Calculator_NX")) {
        brls::Logger::error("Unable to init the Cakculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    }

    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}
