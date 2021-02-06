#pragma once
#include <borealis.hpp>

// Code taken and modified from the borealis example

struct CalculatorTab : public brls::Box {
    CalculatorTab();

    static brls::View* create();

};