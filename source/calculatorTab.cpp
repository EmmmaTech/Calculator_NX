#include <calculatorTab.hpp>

CalculatorTab::CalculatorTab()
{
    this->inflateFromXMLRes("xml/tabs/calculator.xml");
}

brls::View* CalculatorTab::create()
{
    return new CalculatorTab();
}