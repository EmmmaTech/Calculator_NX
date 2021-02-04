#pragma once
#include <borealis.hpp>

struct CalculatorTab : public brls::Box {
    CalculatorTab();

    static brls::View* create();

    private:
    bool onAdditionButtonClicked(brls::View* view);
    bool onSubtractionButtonClicked(brls::View* view);
    bool onMutiplicationButtonClicked(brls::View* view);
    bool onDivisionButtonClicked(brls::View* view);
}