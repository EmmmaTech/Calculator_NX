#pragma once

#include <borealis.hpp>

#ifdef __SWITCH__
#include <switch.h>
#endif

#include "calculator.hpp"
#include <string>
#include <iostream>
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

    bool onScreenButtonClicked(brls::View* view);

    std::string operation;

    BRLS_BIND(brls::Button, cal_button, "cal_screen");
};