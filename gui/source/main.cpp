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

#include <string>
#include <filesystem>
#include <switch.h>
#include <borealis.hpp>
#include "calculatorTab.hpp"
#include "mainActivity.hpp"
#include "aboutTab.hpp"
#include "updateActivity.hpp"
#include "updaterTab.hpp"
#include "constants.hpp"
#include "download.hpp"

using namespace brls::literals;

int main(int argc, char* argv[]) {
    bool versionsSame;

    if (!std::filesystem::exists(DOWNLOAD_PATH)) std::filesystem::create_directories(DOWNLOAD_PATH);

    socketInitializeDefault();

    // Set up the logger 
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    std::string version_from_api = getLatestTag(std::string(API_URL));
    std::string currentVersion = std::string(APP_VERSION);
    versionsSame = version_from_api == currentVersion;

    // Init the app and i18n
    if (!brls::Application::init()) {
        // If the program fails init process, it reports this and stops
        brls::Logger::error("Unable to init the Calculator_NX gui. Please report this to EmreTech");
        return false;
    }

    brls::Application::createWindow("nxgui/title"_i18n);

    brls::Application::setGlobalQuit(true);

    // Initlize the XML configs
    brls::Application::registerXMLView("CalculatorTab", CalculatorTab::create);
    brls::Application::registerXMLView("AboutTab", AboutTab::create);

    if (!versionsSame)
        brls::Application::registerXMLView("UpdaterTab", UpdaterTab::create);

    // If the program is sucessfull with the init process, it pushes the whole GUI
    if (versionsSame)
        brls::Application::pushActivity(new MainActivity());
    else
        brls::Application::pushActivity(new UpdateActivity());

    // Main application loop
    while (brls::Application::mainLoop());

    socketExit();

    // When the loop exits, it reports a successful exit
    return EXIT_SUCCESS;
}
