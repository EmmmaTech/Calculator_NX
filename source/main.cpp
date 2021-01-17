// Include libraries for the calculator program
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "calculator.hpp"

// Include additional libraries for the Switch program
#include <cstdio>
#include <cstdlib>
#include <switch.h>

int main(int argc, char* argv[]) {
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    Result rc = 0;
    MathCalculator calculator{};
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
                swkbdConfigSetGuideText(&kbd, "Type any two numbers with a space in-between (i.e. 10 10)");

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

            std::string keyboardResponse(tmpoutstr);
            int a;
            int b;
            
            int pos = keyboardResponse.find(" ");

            std::string a_str = keyboardResponse.substr(0, pos);
            std::string b_str = keyboardResponse.substr(pos + 1);

            bool a_result = calculator.contains_number(a_str);
            bool b_result = calculator.contains_number(b_str);

            if (a_result && b_result){
                a = std::stoi(a_str);
                b = std::stoi(b_str);
            }
            else {
                std::cout << "Any letters or symbols are not numbers. Please use numbers." << "\n";
                break;
            }

            int answer = calculator.CalculateInt(operation, a, b);

            std::cout << "The answer to " << a << operation << b << " is " << answer << "." << "\n";

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