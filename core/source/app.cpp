#include "app.hpp"

#include "gui_app.hpp"
#include <filesystem>
#include <fstream>
#include "constants.hpp"

void run_app() {
    /*std::filesystem::path gui_default{ CONFIG_PATH };
    gui_default.append(GUI_DEFAULT_FILE);
    std::filesystem::path cmd_default{ CONFIG_PATH };
    cmd_default.append(CMD_DEFAULT_FILE);

    if (!std::filesystem::exists(CONFIG_PATH)) {
        std::filesystem::create_directory(CONFIG_PATH);
    }*/

    while (cmdAppRunning) {
        consoleInit(NULL);

        // Configure our supported input layout: a single player with standard controller styles
        padConfigureInput(1, HidNpadStyleSet_NpadStandard);

        // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
        PadState pad;
        padInitializeDefault(&pad);

        Result rc = 0;
    
        std::string operation;
        char tmpoutstr[16] = {0};

        std::cout << "Press up for Addition, \ndown for Subtraction, \nleft for Mutiplication, \nand right for Division." << std::endl;
        std::cout << "L to Calculate, Y to switch to GUI mode, Plus to exit" << std::endl;

        // Main loop
        while (appletMainLoop())
        {
            // Scan the gamepad. This should be done once for each frame
            padUpdate(&pad);

            // padGetButtonsDown returns the set of buttons that have been
            // newly pressed in this frame compared to the previous one
            u64 kDown = padGetButtonsDown(&pad);

            if (kDown & HidNpadButton_Plus) {
                cmdAppRunning = false;
                break; // break in order to return to hbmenu
            }

            if (kDown & HidNpadButton_Y) {
                /*if (std::filesystem::exists(cmd_default)) {
                    try {
                        std::filesystem::remove(cmd_default);
                    } catch (const std::filesystem::filesystem_error& e) {
                        std::cout << "Filesystem error: " << e.what() << std::endl;
                    }

                    std::fstream gui_file;
                    gui_file.open(gui_default.c_str(), std::ios::out|std::ios::app);
                    gui_file.close();

                    std::cout << "Reopen the app to apply the changes." << std::endl;
                }*/
                cmdAppRunning = false;
                guiAppRunning = true;
            }
            
            if (kDown & HidNpadButton_Up) {
                operation = "+";
                std::cout << "Operation set as: " << operation << "\n";
            }
            else if (kDown & HidNpadButton_Down) {
                operation = "-";
                std::cout << "Operation set as: " << operation << "\n";
            }
            else if (kDown & HidNpadButton_Left) {
                operation = "*";
                std::cout << "Operation set as: " << operation << "\n";
            }
            else if (kDown & HidNpadButton_Right) {
                operation = "/";
                std::cout << "Operation set as: " << operation << "\n";
            }

            if (kDown & HidNpadButton_L && !operation.empty()) {
                std::string fullNums;

                SwkbdConfig kbd;
                rc = swkbdCreate(&kbd, 0);

                if (R_SUCCEEDED(rc)) {
                    // Select a Preset to use, if any.
                    swkbdConfigMakePresetDefault(&kbd);
                    //swkbdConfigMakePresetPassword(&kbd);
                    //swkbdConfigMakePresetUserName(&kbd);
                    //swkbdConfigMakePresetDownloadCode(&kbd);

                    // Optional, set any text if you want (see swkbd.h).
                    //swkbdConfigSetOkButtonText(&kbd, "Submit");
                    //swkbdConfigSetLeftOptionalSymbolKey(&kbd, "a");
                    //swkbdConfigSetRightOptionalSymbolKey(&kbd, "b");
                    //swkbdConfigSetHeaderText(&kbd, "Header");
                    //swkbdConfigSetSubText(&kbd, "Sub");
                    swkbdConfigSetGuideText(&kbd, "Enter all numbers with a space in-between: ");

                    // Set the initial string if you want.
                    //swkbdConfigSetInitialText(&kbd, "Initial");

                    // You can also use swkbdConfigSet*() funcs if you want.

                    //printf("Running swkbdShow...\n");
                    rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));
                    //printf("swkbdShow(): 0x%x\n", rc);

                    swkbdClose(&kbd);
                }

                std::string full_nums = std::string(tmpoutstr);

                std::cout << "The answer is: " << Calculator::solve(full_nums, operation) << std::endl;

                // I just noticed that the string below says \nand at some point
                std::cout << "Press up for Addition, \ndown for Subtraction, \nleft for Mutiplication, \nand right for Division." << "\n";
                std::cout << "L to Calculate, Y to switch to GUI mode, Plus to exit" << "\n";
            }
            
            //std::cout << operation << "\n";

            // Update the console, sending a new frame to the display
            consoleUpdate(NULL);
        } 
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
}