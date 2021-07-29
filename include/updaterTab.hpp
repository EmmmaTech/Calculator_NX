#pragma once

#include <borealis.hpp>

struct UpdaterTab : public brls::Box
{
    UpdaterTab();

    static brls::View* create();

    private:
    BRLS_BIND(brls::Label, MainLabel, "mainLabel");
};