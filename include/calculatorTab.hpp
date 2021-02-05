#pragma once
#include <borealis.hpp>

// Code taken and modified from the borealis example

struct CalculatorTab : public brls::Box {
    CalculatorTab();

    static brls::View* create();

    private:
    bool onAdditionButtonClicked(brls::View* view);
    bool onSubtractionButtonClicked(brls::View* view);
    bool onMutiplicationButtonClicked(brls::View* view);
    bool onDivisionButtonClicked(brls::View* view);
};