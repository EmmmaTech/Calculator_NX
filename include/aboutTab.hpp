#pragma once
#include <borealis.hpp>

// Code taken and modified from the borealis example

struct AboutTab : public brls::Box {
    AboutTab();
    ~AboutTab();

    static brls::View* create();
};