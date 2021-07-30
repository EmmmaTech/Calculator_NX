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

std::string getLatestTag(bool nightly)
{
    if (!downloadFile(
        (nightly ? TAGS_API_LINK : LATEST_RELEASE_API_LINK), DOWNLOAD_PATH + std::string("/github_api.json")
    ))
        return "";

    nlohmann::json api_data;
    std::ifstream api_file(DOWNLOAD_PATH + std::string("/github_api.json"));

    api_file >> api_data;
    api_file.close();

    if (nightly)
        return api_data[0]["name"].get<std::string>();

    return api_data["tag_name"];
}

std::string getLatestDownload(bool nightly)
{
    if (nightly)
    {
        std::string latestTag = getLatestTag(nightly);
        return fmt::format(BASE_DOWNLOAD_URL, latestTag);
    }

    if (!downloadFile(
        LATEST_RELEASE_API_LINK, DOWNLOAD_PATH + std::string("/github_api_two.json")
    ))
        return "";

    nlohmann::json api_data;
    std::ifstream api_file(DOWNLOAD_PATH + std::string("/github_api_two.json"));

    api_file >> api_data;
    api_file.close();

    return api_data["assets"][0]["browser_download_url"];
}