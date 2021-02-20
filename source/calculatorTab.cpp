#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("xml/tabs/calculator.xml");

    BRLS_REGISTER_CLICK_BY_ID("button_add", this->onAdditionButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_subtract", this->onSubtractButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_mutiply", this->onMultiplyButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_divide", this->onDivideButtonClicked);
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

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}