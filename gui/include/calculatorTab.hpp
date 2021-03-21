/*
    Copyright (c) 2021 EmreTech

    Licensed under the MIT License.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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