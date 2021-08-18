#include <aboutTab.hpp>


AboutTab::AboutTab()
{
    this->inflateFromXMLRes("xml/tabs/about.xml");
}

brls::View *AboutTab::create()
{
    return new AboutTab();
}