#include <borealis.hpp>

#include <switch.h>
#include <cstdio>
#include <cstdlib>

#include "calculator.hpp"
#include <string>
#include <sstream>
#include <vector>

// Code taken and modified from the borealis example

struct CalculatorTab : public brls::Box {
    CalculatorTab();
    ~CalculatorTab();

    static brls::View* create();

    private:
    bool onAdditionButtonClicked(brls::View* view);
    bool onSubtractButtonClicked(brls::View* view);
    bool onMultiplyButtonClicked(brls::View* view);
    bool onDivideButtonClicked(brls::View* view);

    bool onScreenButtonClicked(brls::View* view) {
        brls::Logger::debug("Screen button clicked");

        brls::Logger::info("Operation is set as: " + operation);

        std::vector<float> vec;

        char tmpoutstr[16] = {0};
        SwkbdConfig kbd;
        Result rc = swkbdCreate(&kbd, 0);

        if (R_SUCCEEDED(rc)) {
            swkbdConfigMakePresetDefault(&kbd);
            swkbdConfigSetGuideText(&kbd, "Enter all numbers with a space in-between: ");

            rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));

            swkbdClose(&kbd);
        }

        std::istringstream iss(tmpoutstr);
        std::string Num;

        while (iss >> Num) {
            vec.emplace_back(std::stof(Num));
        }
        
        float answer = Calculator::solve(vec, operation);

        std::cout << "The answer is: " << answer << std::endl;

        return true;
    }

    std::string operation;
};