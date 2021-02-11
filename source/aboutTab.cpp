#include "aboutTab.hpp"

// Code taken and modified from the borealis example

AboutTab::AboutTab() {
    this->inflateFromXMLRes("xml/tabs/about.xml");
}

AboutTab::~AboutTab() {
    brls::Logger::debug("AboutTab struct destroyed");
}

brls::View* AboutTab::create() {
    return new AboutTab();
}