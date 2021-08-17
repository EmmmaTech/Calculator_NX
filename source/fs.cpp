#include <fs.hpp>

#include <switch.h>
#include <fstream>

namespace fs
{
    bool copy(const char *to, const char *from)
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

    bool move(const char *to, const char *from)
    {
        return copy(to, from) && std::filesystem::remove(from);
    }

    nlohmann::json parseJsonFile(const std::string &filepath)
    {
        std::ifstream file(filepath);
        std::string fContent = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

        if (nlohmann::json::accept(fContent))
            return nlohmann::json::parse(fContent);
        else
            return nlohmann::json::object();
    }
} // namespace fs
