#pragma once

#include <borealis.hpp>

struct AboutTab : public brls::Box
{
    AboutTab();

    static brls::View* create();

    private:
    BRLS_BIND(brls::Label, versionLabel, "Version Label");
};