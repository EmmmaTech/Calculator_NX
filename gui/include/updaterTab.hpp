#pragma once

#include <borealis.hpp>

struct UpdaterTab : public brls::Box {
    UpdaterTab();

    static brls::View* create();

    private:
    bool onYesButtonClicked(brls::View* view);
    bool onNoButtonClicked(brls::View* view);

    BRLS_BIND(brls::Label, verboseLabel, "verbose_label");
};