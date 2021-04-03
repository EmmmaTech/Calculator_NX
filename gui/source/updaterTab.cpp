/*
    Copyright (c) 2021 EmreTech

    Licensed under the MIT License.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "updaterTab.hpp"

#include "download.hpp"
#include "constants.hpp"
#include <string>
#include <filesystem>
#include <fstream>
#include <switch.h>

bool copyFile(const std::string &from, const std::string &to){
        std::ifstream src(from, std::ios::binary);
        std::ofstream dst(to, std::ios::binary);

        if (src.good() && dst.good()) {
            dst << src.rdbuf();
            return true;
        }
        return false;
}

UpdaterTab::UpdaterTab() {
    this->inflateFromXMLRes("xml/tabs/updater.xml");

    BRLS_REGISTER_CLICK_BY_ID("yes", this->onYesButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("no", this->onNoButtonClicked);
}

bool UpdaterTab::onYesButtonClicked(brls::View* view) {
    brls::Logger::debug("Grabbing URL...");

    //this->verboseLabel->setText("Finding the URL for the app...");
    std::string url_download = getLatestDownload(API_URL);
    brls::Logger::debug("Found URL! It's {}.", url_download);

    //this->verboseLabel->setText("URL found! Downloading from URL...");
    downloadFile(url_download.c_str(), NRO_DOWNLOAD_PATH);
    brls::Logger::debug("File downloaded!");

    //this->verboseLabel->setText("File downloaded! Moving to the /switch folder...");
    if (std::filesystem::exists(NRO_PATH_1)) {
        brls::Logger::debug("{} exists!", NRO_PATH_1);
        copyFile(NRO_DOWNLOAD_PATH, std::string(SWITCH_PATH) + "Calculator_NX_New.nro");
        std::filesystem::remove(NRO_PATH_1);
        std::filesystem::rename(std::string(SWITCH_PATH) + "Calculator_NX_New.nro", NRO_PATH_1);
        return true;
    }
    else {
        brls::Logger::debug("{} exists!", NRO_PATH_2);
        copyFile(NRO_DOWNLOAD_PATH, std::string(CALCULATOR_NX_PATH) + "Calculator_NX_New.nro");
        std::filesystem::remove(NRO_PATH_2);
        std::filesystem::rename(std::string(CALCULATOR_NX_PATH) + "Calculator_NX_New.nro", NRO_PATH_2);
        return true;
    }

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