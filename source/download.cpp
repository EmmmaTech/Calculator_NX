#include <download.hpp>

#include <nlohmann/json.hpp>
#include <fmt/core.h>

#include <constants.hpp>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
CURLcode downloadFile(const std::string &url, const std::string &filename)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(filename.c_str(), "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_USERAGENT, API_AGENT);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        fclose(fp);
    }

    return res;
}

std::string getLatestTag(bool nightly)
{
    downloadFile(
        (nightly ? TAGS_API_LINK : LATEST_RELEASE_API_LINK), DOWNLOAD_PATH + std::string("/github_api.json")
    );

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

    downloadFile(
        LATEST_RELEASE_API_LINK, DOWNLOAD_PATH + std::string("/github_api_two.json")
    );

    nlohmann::json api_data;
    std::ifstream api_file(DOWNLOAD_PATH + std::string("/github_api_two.json"));

    api_file >> api_data;
    api_file.close();

    return api_data["assets"][12/*"browser_download_url"*/];
}