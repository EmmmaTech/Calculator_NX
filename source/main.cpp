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
    //std::cout << "The answer is: " << answer << "\n";
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

        //std::cout << "The answer to " << num1 << " " << operation << " " << num2 << "is " << answer << "\n";
    } else return;
}

int main(int argc, char* argv[]) {
    std::vector<int> StoredInts{};

    MathCalculator calculator{StoredInts};
    std::string operation{};

    return 0;
}
