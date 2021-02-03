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
#include "borealis/library/include/borealis.hpp"

char* SoftwareKeyboard(Result rc, const char * guideText) {
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

        /*if (R_SUCCEEDED(rc)) {
                    printf("out str: %s\n", tmpoutstr);
        }*/
        swkbdClose(&kbd);
    }

    return tmpoutstr;
}

void calculateVectorInts(std::string operation, MathCalculator& calculator, Result& rc) {
    std::string number;
    char * tmpoutstr;
    bool inputComplete = false;

    while(!inputComplete) {
        tmpoutstr = SoftwareKeyboard(rc, "Enter one number at a time (q to stop)");
        number = std::string(tmpoutstr);

        if (number == "q") {
            inputComplete = true;
        } else {
            if (calculator.contains_number(number)) {
                    calculator.setVector(std::stoi(number));
            } else inputComplete = true;
    }

    int answer = calculator.CalculateMoreInt(operation);
    std::cout << "The answer is: " << answer << "\n";
}
}

void calculateTwoInts(std::string operation, MathCalculator& calculator, Result& rc) {
    std::string number1;
    std::string number2;

    char * tmpoutstr = SoftwareKeyboard(rc, "Enter two numbers with a space in-between");
    std::string keyboardInput(tmpoutstr);

    int pos = keyboardInput.find(" ");

    number1 = keyboardInput.substr(0, pos);
    number2 = keyboardInput.substr(pos + 1);

    int num1;
    int num2;

    if (calculator.contains_number(number1) && calculator.contains_number(number2)) {
        num1 = std::stoi(number1);
        num2 = std::stoi(number2);

        int answer = calculator.CalculateInt(operation, num1, num2);

        std::cout << "The answer to " << num1 << " " << operation << " " << num2 << "is " << answer << "\n";
    } else return;
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
            std::cout << "A for calculating more than 2 numbers, B for calculating only 2 numbers\n";
            if (kDown & HidNpadButton_A) {
                calculateVectorInts(operation, calculator, rc);
            } else if (kDown & HidNpadButton_B) {
                calculateTwoInts(operation, calculator, rc);
            }

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
