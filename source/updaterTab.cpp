#include <updaterTab.hpp>

#include <fmt/core.h>
#include <switch.h>

#include <download.hpp>
#include <constants.hpp>
#include <fs.hpp>
#include <mainActivity.hpp>
#include <config.hpp>

using namespace brls::literals;

const std::string updaterTabXml = R"xml(
    <brls:Box
        width="auto"
        height="auto"
        justifyContent="center"
        alignItems="center"
        axis="column">

        <brls:Label
            id="mainLabel"
            width="auto"
            height="auto"
            fontSize="24"
            text="@i18n/text/updater/checking"
            marginBottom="30px"/>

        <brls:Button
            id="continue"
            width="auto"
            height="30"
            style="primary"
            text="Continue"/>

    </brls:Box>
)xml";

// TODO: Fix crash when selecting the updater tab in main frame

UpdaterTab::UpdaterTab()
{
    this->inflateFromXMLString(updaterTabXml);

    BRLS_REGISTER_CLICK_BY_ID("continue", this->onContinueButton);
    ContinButton->hide([]{});

    currentTagVersion = "v{}";
    if (STABLE == std::string("Nightly"))
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM) + "-nightly";
    else
        currentTagVersion = fmt::format(currentTagVersion, VERSION_NUM);

    newTag = getLatestTag(Config::getInstance().isNightly);

   if (currentTagVersion != newTag)
   {
        MainLabel->setText("text/updater/new_update"_i18n);
        ContinButton->show([]{});
    }
    else
        MainLabel->setText("text/updater/no_update"_i18n);
    
}

brls::View* UpdaterTab::create()
{
    return new UpdaterTab();
}

bool UpdaterTab::onContinueButton(brls::View *view)
{
    std::string urlLink = getLatestDownload(Config::getInstance().isNightly);
    downloadFile(urlLink, DOWNLOAD_PATH "Calculator_NX.nro");
    fs::copy(CONFIG_FORWARDER_PATH, ROMFS_FORWARDER_PATH);
    envSetNextLoad(CONFIG_FORWARDER_PATH, ("\"" + std::string(CONFIG_FORWARDER_PATH) + "\"").c_str());

    ContinButton->hide([]{});
    MainLabel->setText("text/updater/exit_message"_i18n);
    return true;
}