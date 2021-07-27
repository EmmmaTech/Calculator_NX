#include <filesystem>

namespace fs
{
    int removeAllFilesInFolder(const char *path);
    bool copyFile(const char *to, const char *from);
} // namespace fs