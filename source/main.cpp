// Include libraries for the calculator program
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <stdexcept>
#include <exception>
#include <new>
#include "calculator.hpp"

// Include additional libraries for the Switch program
#include <cstdio>
#include <cstdlib>
#include <switch.h>

std::string compareNumberString(bool result, std::string str, int decider) {
    MathCalculator math{};

    if (result){
        int newInt = std::stoi(str);
        int& newNewInt = newInt;
        math.setAorB(decider, newNewInt);
        std::cout << math.getAorB(decider) << "\n";
        return "NUMBER";
    }
    else return "LETTER";
    

    return "NULL";
}

constexpr void assert_that(bool condition, const char* message) {
    if (!condition) throw std::runtime_error{ message };
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        std::cout << "[+] Test " << name << " successful.\n";
    } catch (const std::exception& e) {
        std::cout << "[-] Test failure in " << name << ". " << e.what() << "\n";
    }
}

void testVariables() {
    MathCalculator math{};
    int a = math.getAorB(1);
    int b = math.getAorB(2);

    std::cout << a << " " << b << "\n";

    return assert_that(a != 0 && b != 0, "Variable was set to 0 instead of a different number.");
}

int main(int argc, char* argv[]) {
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    Result rc = 0;

    int a = 5;
    int b = 5;
    MathCalculator calculator{a, b};
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
            
            int pos = keyboardResponse.find(" ");

            std::string a_str = keyboardResponse.substr(0, pos);
            std::string b_str = keyboardResponse.substr(pos + 1);

            bool a_result = calculator.contains_number(a_str);
            bool b_result = calculator.contains_number(b_str);

            std::string compare_result_a = compareNumberString(a_result, a_str, 1);
            std::string compare_result_b = compareNumberString(b_result, b_str, 2);

            /*if (compare_result_a == "NUMBER" && compare_result_b == "NUMBER") {
                a = calculator.getAorB(1);
                b = calculator.getAorB(2);

                std::cout << a << " " << b << " " << operation << "\n";

                int answer = calculator.CalculateInt(operation, a, b);
                std::cout << "The answer to " << a << operation << b << " is " << answer << "." << "\n";
            } else if (compare_result_a == "LETTER" || compare_result_b == "LETTER") {
                std::cout << "Please use numbers instead of letters/symbols." << "\n";
            } else {}*/

            run_test(testVariables, "variables are set to what the user inputs");

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