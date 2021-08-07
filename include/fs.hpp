#pragma once

#include <filesystem>
#include <nlohmann/json.hpp>

namespace fs
{   
    void copy(const char *to, const char *from);
    void move(const char *to, const char *from);

    nlohmann::json parseJsonFile(const std::string &filepath);
} // namespace fs