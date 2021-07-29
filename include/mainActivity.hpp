#pragma once

#include <borealis.hpp>

struct MainActivity : public brls::Activity
{
    brls::View* createContentView() override;
};