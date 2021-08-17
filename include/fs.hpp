#pragma once

#include <filesystem>
#include <nlohmann/json.hpp>

namespace fs
{   
    bool copy(const char *to, const char *from);
    bool move(const char *to, const char *from);

    nlohmann::json parseJsonFile(const std::string &filepath);
} // namespace fs