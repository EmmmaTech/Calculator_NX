#include "aboutTab.hpp"

// Code taken and modified from the borealis example and unused

AboutTab::AboutTab() {
    this->inflateFromXMLRes("fu");
}

AboutTab::~AboutTab() {
    brls::Logger::debug("AboutTab struct destroyed");
}

brls::View* AboutTab::create() {
    return new AboutTab();
}