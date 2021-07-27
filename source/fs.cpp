#include <fs.hpp>

#include <switch.h>

#include <fstream>

namespace fs
{
    int removeAllFilesInFolder(const char *path)
    {
        Result res = 0;
        FsFileSystem *fs = fsdevGetDeviceFileSystem("sdmc");

        res = fsFsDeleteDirectoryRecursively(fs, path);
        return res;
    }

    bool copyFile(const char *to, const char *from)
    {
        std::ifstream src(from, std::ios::binary);
        std::ofstream dst(to, std::ios::binary);

        if (src.good() && dst.good())
        {
            dst << src.rdbuf();
            return true;
        }
        return false;
    }

} // namespace fs
