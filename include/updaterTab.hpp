#pragma once

#include <borealis.hpp>

struct UpdaterTab : public brls::Box
{
    UpdaterTab();

    static brls::View* create();

    private:
    bool onContinueButton(brls::View *view);

    BRLS_BIND(brls::Label, MainLabel, "mainLabel");
    BRLS_BIND(brls::Button, ContinButton, "continue");

    std::string currentTagVersion, newTag;
    bool isNightly;
};