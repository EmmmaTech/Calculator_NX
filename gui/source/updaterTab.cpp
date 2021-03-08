#include "updaterTab.hpp"

#include "utils.hpp"
#include "constants.hpp"
#include <string>
#include <filesystem>

UpdaterTab::UpdaterTab() {
    this->inflateFromXMLRes("xml/tabs/updater.xml");

    BRLS_REGISTER_CLICK_BY_ID("yes", this->onYesButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("no", this->onNoButtonClicked);
}

bool UpdaterTab::onYesButtonClicked(brls::View* view) {
    //TODO: Actually update the app
    this->verboseLabel->setText("Finding the URL for the app...");
    std::string url_download = getLatestDownload(API_URL);

    this->verboseLabel->setText("URL found! Downloading from URL...");
    downloadFile(url_download.c_str(), NRO_DOWNLOAD_PATH);

    this->verboseLabel->setText("File downloaded! Moving to the /switch folder...");
    if (std::filesystem::exists(NRO_PATH_1))
        std::filesystem::copy_file(NRO_DOWNLOAD_PATH, NRO_PATH_1);
    else
        std::filesystem::copy_file(NRO_DOWNLOAD_PATH, NRO_PATH_2);

    return true;
}

bool UpdaterTab::onNoButtonClicked(brls::View* view) {
    //TODO: Add a way to ignore an update. Until then, it'll excute the same code from onYesButtonClicked
    this->verboseLabel->setText("Finding the URL for the app...");
    std::string url_download = getLatestDownload(API_URL);

    this->verboseLabel->setText("URL found! Downloading from URL...");
    downloadFile(url_download.c_str(), NRO_DOWNLOAD_PATH);

    this->verboseLabel->setText("File downloaded! Moving to the /switch folder...");
    if (std::filesystem::exists(NRO_PATH_1))
        std::filesystem::copy_file(NRO_DOWNLOAD_PATH, NRO_PATH_1);
    else
        std::filesystem::copy_file(NRO_DOWNLOAD_PATH, NRO_PATH_2);

    return true;
}

brls::View* UpdaterTab::create() {
    return new UpdaterTab();
}