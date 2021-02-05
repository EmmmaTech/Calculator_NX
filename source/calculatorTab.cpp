#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("calculator.xml");

    BRLS_REGISTER_CLICK_BY_ID("buttons_addition", this->onAdditionButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("buttons_subtraction", this->onSubtractionButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("buttons_mutiplication", this->onMutiplicationButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("buttons_division", this->onDivisionButtonClicked);
}

bool CalculatorTab::onAdditionButtonClicked(brls::View* view) {
    // TODO: actually do something here
    brls::Logger::info("Clicked Addition");
    return true;
}

bool CalculatorTab::onSubtractionButtonClicked(brls::View* view) {
    // TODO: actually do something here
    brls::Logger::info("Clicked Subtraction");
    return true;
}

bool CalculatorTab::onMutiplicationButtonClicked(brls::View* view) {
    // TODO: actually do something here
    brls::Logger::info("Clicked Mutiplication");
    return true;
}

bool CalculatorTab::onDivisionButtonClicked(brls::View* view) {
    // TODO: actually do something here
    brls::Logger::info("Clicked Division");
    return true;
}

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}