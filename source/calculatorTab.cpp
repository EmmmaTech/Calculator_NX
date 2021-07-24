#include <calculatorTab.hpp>

#include <vector>
#include <utility>

#include <calculator.hpp>

std::vector<std::pair<std::string,char>> allButtons {
    std::make_pair("(Button", '('),
    std::make_pair(")Button", ')'),
    std::make_pair("9Button", '9'),
    std::make_pair("6Button", '6'),
    std::make_pair("3Button", '3'),
    std::make_pair("0Button", '0'),
    std::make_pair("8Button", '8'),
    std::make_pair("5Button", '5'),
    std::make_pair("2Button", '2'),
    std::make_pair("DotButton", '.'),
    std::make_pair("7Button", '7'),
    std::make_pair("4Button", '4'),
    std::make_pair("1Button", '1'),
    std::make_pair("PlusButton", '+'),
    std::make_pair("MinusButton", '-'),
    std::make_pair("MultiplyButton", '*'),
    std::make_pair("DivideButton", '/'),
};

CalculatorTab::CalculatorTab()
{
    this->inflateFromXMLRes("xml/tabs/calculator.xml");

    for (auto &e : allButtons)
    {
        char c = e.second;

        this->getView(e.first)->registerAction(
            "", brls::BUTTON_A, 
            [this, c](brls::View *view) {
                onButtonPressed(c); 
                return true;
            },
            false, brls::SOUND_CLICK
        );
    }

    BRLS_REGISTER_CLICK_BY_ID("EqualButton", this->onEqualButtonPressed);
    BRLS_REGISTER_CLICK_BY_ID("DelButton", this->onDeleteButtonPressed);
}

brls::View* CalculatorTab::create()
{
    return new CalculatorTab();
}

void CalculatorTab::onButtonPressed(char c)
{
    expressionStr += c;
    updateScreenBufferFromExpStr();
} 

bool CalculatorTab::onEqualButtonPressed(brls::View *view)
{
    if (expressionStr != "")
    {
        double result = Calculator::getInstance().evaluateExpression(expressionStr);
        screenBuffer += " = " + std::to_string(result);
        updateScreen();

        expressionStr = "";
    }
    return true;
}

bool CalculatorTab::onDeleteButtonPressed(brls::View *view)
{
    if (expressionStr != "")
    {
        expressionStr.pop_back();
        updateScreenBufferFromExpStr();
    }
    
    return true;
}

void CalculatorTab::updateScreen()
{
    screenLabel->setText(screenBuffer);
}

void CalculatorTab::updateScreenBufferFromExpStr()
{
    screenBuffer = expressionStr;
    if (expressionStr.length() >= 30)
        screenBuffer = expressionStr.substr(29);
    updateScreen();
}