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
            fontSize="15"
            text="@i18n/text/updater/checking"/>

    </brls:Box>
)xml";

UpdaterTab::UpdaterTab()
{
    this->inflateFromXMLString(updaterTabXml);

    std::string currentTagVersion = "v{0}{1}";
    if (STABLE == std::string("Nightly"))
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM, "-nightly");
    else
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM);

    brls::Logger::debug("Current version in GitHub tag format: {}", currentTagVersion);

    if (getLatestTag(STABLE == std::string("Nightly")) != currentTagVersion)
    {
        std::string downloadUrl = getLatestDownload(STABLE == std::string("Nightly"));
        downloadFile(downloadUrl, DOWNLOAD_PATH + std::string("/Calculator_NX.nro"));
        fs::copyFile(CONFIG_FORWARDER_PATH, ROMFS_FORWARDER_PATH);
        brls::Application::quit();
        envSetNextLoad(CONFIG_FORWARDER_PATH, ("\"" + std::string(CONFIG_FORWARDER_PATH) + "\"").c_str());
    }
}

brls::View* UpdaterTab::create()
{
    return new UpdaterTab();
}