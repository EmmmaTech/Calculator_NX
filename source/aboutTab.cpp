#include "aboutTab.hpp"

// Code taken and modified from the borealis example

AboutTab::AboutTab() {
    this->inflateFromXMLRes("tabs/about.xml");
}

brls::View* AboutTab::create() {
    return new AboutTab();
}