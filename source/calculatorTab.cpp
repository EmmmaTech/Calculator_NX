#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("tabs/calculator.xml");
}

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}