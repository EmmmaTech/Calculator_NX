//////////////////////////////////////////////////////
// BBBBBBB   RRRRRRR  EEEEEEEE      A      DDDDDD   //
// B      B  R     R  E            A A     D     D  //
// BBBBBBB   RRRRRRR  EEEEEEEE    A   A    D      D //
// B      B  R  RR    E          AAAAAAA   D     D  //
// BBBBBBB   R    RR  EEEEEEEE  A       A  DDDDDD   //
//////////////////////////////////////////////////////                 

// Decicated to the love of bread in RetroNX.

#include <borealis.hpp>
#include <http.hpp>
#include <nlohmann/json.hpp>

#include <fs.hpp>
#include <constants.hpp>
#include <mainActivity.hpp>
#include <download.hpp>

using namespace brls::literals;

int main(int argc, char *argv[])
{
    // File-related checks before booting

    if (!std::filesystem::exists(DOWNLOAD_PATH))
        std::filesystem::create_directories(DOWNLOAD_PATH);

    // Init the borealis application

    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }
    brls::Application::createWindow("text/title"_i18n);
    brls::Application::setGlobalQuit(true);

    if (!httpInitialize())
    {
        brls::Logger::error("Could not initialize CURL, quitting...");
        brls::Application::quit();
        return EXIT_FAILURE;
    }

    // Push activity

    brls::Application::pushActivity(new MainActivity());

    // Start the main application loop

    while (brls::Application::mainLoop());

    httpExit();
    return EXIT_SUCCESS;
}