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

#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

template < typename Type > std::string to_str (const Type & t) {
  std::ostringstream os;
  os << t;
  return os.str();
}

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("xml/tabs/calculator.xml");

    BRLS_REGISTER_CLICK_BY_ID("button_add", this->onAdditionButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_subtract", this->onSubtractButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_mutiply", this->onMultiplyButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_divide", this->onDivideButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("cal_screen", this->onScreenButtonClicked);
}

CalculatorTab::~CalculatorTab() {
    brls::Logger::debug("CalculatorTab struct destroyed");
}

bool CalculatorTab::onAdditionButtonClicked(brls::View* view) {
    brls::Logger::debug("Addition button clicked");

    operation = "+";
    return true;
}

bool CalculatorTab::onSubtractButtonClicked(brls::View* view) {
    brls::Logger::debug("Subtraction button clicked");

    operation = "-";
    return true;
}

bool CalculatorTab::onMultiplyButtonClicked(brls::View* view) {
    brls::Logger::debug("Multiply button clicked");

    operation = "*";
    return true;
}

bool CalculatorTab::onDivideButtonClicked(brls::View* view) {
    brls::Logger::debug("Divide button clicked");

    operation = "/";
    return true;
}

bool CalculatorTab::onScreenButtonClicked(brls::View* view) {
        brls::Logger::debug("Screen button clicked");

        brls::Logger::info("Operation is set as: " + operation);

        if (!operation.empty()) {
            char tmpoutstr[32] = {0};
            #ifdef __SWITCH__
            SwkbdConfig kbd;
            Result rc = swkbdCreate(&kbd, 0);

            if (R_SUCCEEDED(rc)) {
                swkbdConfigMakePresetDefault(&kbd);
                swkbdConfigSetGuideText(&kbd, "Enter all numbers with a space in-between: ");

                rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));

                swkbdClose(&kbd);
            }
            #else

            std::cout << "Enter all numbers with a space in-between: " << std::endl;
            std::cin.getline(tmpoutstr, 32);

            #endif
            
            std::string full_nums = std::string(tmpoutstr);

            float answer = Calculator::solve(full_nums, operation);

            std::cout << "The answer is: " << answer << std::endl;
            this->cal_button->setText("The answer is: " + to_str(answer));

            return true;
        } else {
            this->cal_button->setText("Please select an operation first.");
            return true;
        }
}

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}