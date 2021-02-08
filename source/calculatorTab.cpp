#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("xml/tabs/calculator.xml");
}

CalculatorTab::~CalculatorTab() {
    brls::Logger::debug("CalculatorTab struct destroyed");
}

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}