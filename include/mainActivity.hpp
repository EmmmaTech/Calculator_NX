#pragma once
#include <borealis.hpp>

// Code taken and modified from the borealis example

struct MainActivity : public brls::Activity {
    CONTENT_FROM_XML_RES("activity/main.xml");
};