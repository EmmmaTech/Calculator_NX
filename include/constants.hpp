#pragma once

#define SWITCH_PATH "/switch/"
#define CALCULATOR_NX_PATH SWITCH_PATH "Calculator_NX/"
#define PATH_1 CALCULATOR_NX_PATH "Calculator_NX.nro"
#define PATH_2 SWITCH_PATH "Calculator_NX.nro"

#define CONFIG_PATH "/config/Calculator_NX/"
#define DOWNLOAD_PATH CONFIG_PATH "download/"
#define CONFIG_FORWARDER_PATH CONFIG_PATH "cnx_forwarder.nro"
#define ROMFS_FORWARDER_PATH "romfs:/cnx_forwarder.nro"

#define UPDATER_SETTINGS_PATH CONFIG_PATH "updater_settings.json"

#define TAGS_API_LINK "https://api.github.com/repos/EmreTech/Calculator_NX/tags"
#define LATEST_RELEASE_API_LINK "https://api.github.com/repos/EmreTech/Calculator_NX/releases/latest"

#define BASE_DOWNLOAD_URL "https://github.com/EmreTech/Calculator_NX/releases/download/{}/Calculator_NX.nro"

constexpr const int TRUE = 0;
constexpr const int FALSE = 1;
constexpr const int NEITHER = 2;

#define IS_TRUE(x) x == TRUE
#define IS_FALSE(x) x == FALSE
#define IS_NEITHER(x) x == NEITHER