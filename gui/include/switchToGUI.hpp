#pragma once

#include "app.hpp"
#include <borealis.hpp>
#include "constants.hpp"

struct SwitchToCMD : public brls::Box {
    SwitchToCMD();

    static brls::View* create();

    private:
    bool onButtonClicked(brls::View* view);
    BRLS_BIND(brls::Button, main_button, "main_button");
};