#include <switch.h>

#include <filesystem>
#include <string>

#define PATH "/switch/Calculator_NX"
#define FULL_PATH "/switch/Calculator_NX/Calculator_NX.nro"
#define ALT_PATH "/switch/Calculator_NX.nro"
#define CONFIG_PATH "/config/Calculator_NX/download/Calculator_NX.nro"
#define DONWLOAD_PATH "/config/Calculator_NX/download"
#define FORWARDER_PATH "/config/Calculator_NX/cnx_forwarder.nro"

int removeEverythingInDir(const char *path)
{
    Result res = 0;
    FsFileSystem *fs = fsdevGetDeviceFileSystem("sdmc");

    res = fsFsDeleteDirectoryRecursively(fs, path);
    return res;
}

int main(int argc, char *argv[])
{
    std::filesystem::create_directory(PATH);
    if (std::filesystem::exists(CONFIG_PATH))
    {
        std::filesystem::remove(FULL_PATH);
        std::filesystem::remove(ALT_PATH);
        std::filesystem::rename(CONFIG_PATH, FULL_PATH);
        removeEverythingInDir(DONWLOAD_PATH);
    }

    std::filesystem::remove(FORWARDER_PATH);
    envSetNextLoad(FULL_PATH, ("\"" + std::string(FULL_PATH) + "\"").c_str());

    return EXIT_SUCCESS;
}