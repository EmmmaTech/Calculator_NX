#include <fs.hpp>

#include <switch.h>
#include <fstream>

namespace fs
{
    void copy(const char *to, const char *from)
    {
        // To be implemented...
    }

    void move(const char *to, const char *from)
    {
        // To be implemented...
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
