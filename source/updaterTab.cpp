#include <updaterTab.hpp>

#include <fmt/core.h>
#include <switch.h>

#include <download.hpp>
#include <constants.hpp>
#include <fs.hpp>

using namespace brls::literals;

const std::string updaterTabXml = R"xml(
    <brls:Box
        width="auto"
        height="auto"
        justifyContent="center"
        alignItems="center">

        <brls:Label
            id="mainLabel"
            width="auto"
            height="auto"
            fontSize="25"/>

    </brls:Box>
)xml";

UpdaterTab::UpdaterTab()
{
    this->inflateFromXMLString(updaterTabXml);

    std::string currentTagVersion = "v{}";
    if (STABLE == std::string("Nightly"))
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM) + "-nightly";
    else
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM);

    MainLabel->setText(fmt::format("Current version in GitHub tag format: {}", currentTagVersion));
}

brls::View* UpdaterTab::create()
{
    return new UpdaterTab();
}