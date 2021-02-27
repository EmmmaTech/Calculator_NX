#pragma once

#include "app.hpp"
#include <borealis.hpp>

struct SwitchToCMD : public brls::Box {
    SwitchToCMD();

    static brls::View* create();

    private:
    bool onButtonClicked(brls::View* view);
};