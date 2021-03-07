#include "aboutTab.hpp"

AboutTab::AboutTab() {
    this->inflateFromXMLRes("xml/tabs/about.xml");

    this->image->setImageFromRes("Calculator_NX.jpg");
}

brls::View* AboutTab::create() {
    return new AboutTab();
}