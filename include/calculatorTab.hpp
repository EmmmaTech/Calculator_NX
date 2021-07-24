#pragma once

#include <borealis.hpp>

struct CalculatorTab : public brls::Box
{
    CalculatorTab();

    static brls::View* create();

    private:
    void onButtonPressed(char c);
    bool onEqualButtonPressed(brls::View *view);
    bool onDeleteButtonPressed(brls::View *view);

    void updateScreenBufferFromExpStr();
    void updateScreen();

    BRLS_BIND(brls::Label, screenLabel, "screen");
    std::string expressionStr = "", screenBuffer;
};