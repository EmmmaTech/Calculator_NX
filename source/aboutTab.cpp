#include <aboutTab.hpp>


AboutTab::AboutTab()
{
    this->inflateFromXMLRes("xml/tabs/about.xml");
    versionLabel->setText(VERSION_NUM + std::string(" | ") + STABLE);
}

brls::View *AboutTab::create()
{
    return new AboutTab();
}