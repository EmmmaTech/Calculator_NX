#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <constants.hpp>
#include <singleton.hpp>

class Config
{
    private:
    Config(){}

    public:

    NON_COPYABLE(Config)
    NON_MOVABLE(Config)

    static Config& getInstance()
    {
        static Config cfg;
        return cfg;
    }

    int isNightly = (int) (STABLE == std::string("Nightly"));

    void parseFromJson(nlohmann::json &json)
    {
        try
        {
            isNightly = json["update_channel"].get<int>();
        }
        catch (const std::exception& e)
        {
            return;
        }
    }
};