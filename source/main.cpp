// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include "calculator.hpp"

// Include additional libraries for the Switch program
#include <cstdio>
#include <cstdlib>
#include <switch.h>

char SoftwareKeyboard(char tmpoutstr, Result rc, const char * guideText) {
    SwkbdConfig kbd;
            
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

        /*if (R_SUCCEEDED(rc)) {
                    printf("out str: %s\n", tmpoutstr);
        }*/
        swkbdClose(&kbd);
    }

    return tmpoutstr;
}

int main(int argc, char* argv[]) {
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    Result rc = 0;

    std::vector<int> StoredInts{};

    MathCalculator calculator{StoredInts};
    std::string operation{};
    char tmpoutstr[16] = {0};

    std::cout << "Press up for Addition, \ndown for Subtraction, \nleft for Mutiplication, \nand right for Division." << "\n";
    std::cout << "L to Calculate, Plus to exit" << "\n";

    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus) break; // break in order to return to hbmenu

        // Your code goes here
        
        if (kDown & HidNpadButton_Up) {
            operation = "+";
            std::cout << "Operation set as: " << operation << "\n";
        }
        else if (kDown & HidNpadButton_Down) {
            operation = "-";
            std::cout << "Operation set as: " << operation << "\n";
        }
        else if (kDown & HidNpadButton_Left) {
            operation = "*";
            std::cout << "Operation set as: " << operation << "\n";
        }
        else if (kDown & HidNpadButton_Right) {
            operation = "/";
            std::cout << "Operation set as: " << operation << "\n";
        }

        if (kDown & HidNpadButton_L && !operation.empty()) {
            std::string number;
            bool inputComplete = false;

            while(!inputComplete) {
                tmpoutstr = SoftwareKeyboard(tmpoutstr, rc, "Enter one number at a time (q to stop)");
                number = std::string(tmpoutstr);

                if (number == "q") {
                    inputComplete = true;
                } else {
                    if (calculator.contains_number(number)) {
                        calculator.setVector(std::stoi(number));
                    } else inputComplete = true;
            }

            int answer = calculator.CalculateMoreInt(operation);

            // I just noticed that the string below says \nand at some point
            std::cout << "Press up for Addition, \ndown for Subtraction, \nleft for Mutiplication, \nand right for Division." << "\n";
            std::cout << "L to Calculate, Plus to exit" << "\n";

        }
        
        //std::cout << operation << "\n";

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);


    return 0;
}