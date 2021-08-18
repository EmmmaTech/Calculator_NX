#include <download.hpp>

#include <borealis.hpp>
#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <http.hpp>

#include <fstream>

#include <constants.hpp>

constexpr const char *API_AGENT = "EmreTech";

bool downloadFile(const std::string &url, const std::string &filename)
{
    return httpDownloadFile(filename.c_str(), url.c_str(), false, NULL, NULL);
}

std::string getLatestTag(int nightly)
{
    if (!downloadFile(TAGS_API_LINK, DOWNLOAD_PATH + std::string("/github_api.json")))
        return "";

    nlohmann::json api_data;
    std::ifstream api_file(DOWNLOAD_PATH + std::string("/github_api.json"));

    api_file >> api_data;
    api_file.close();
    
    std::string ret;
    for (auto &e : api_data)
    {
        if (IS_TRUE(nightly))
        {
            if (e["name"].get<std::string>().find("-nightly") == std::string::npos)
                continue;
            else
            {
                ret = e["name"].get<std::string>();
                break;
            }
        }
        else if (IS_FALSE(nightly))
        {
            if (e["name"].get<std::string>().find("-nightly") != std::string::npos || e["name"].get<std::string>().find("-beta") != std::string::npos)
                continue;
            else
            {
                ret = e["name"].get<std::string>();
                break;
            }
        }
    }

    return ret;
}

std::string getLatestDownload(int nightly)
{
    std::string latestTag = getLatestTag(nightly);
    return fmt::format(BASE_DOWNLOAD_URL, latestTag);
}