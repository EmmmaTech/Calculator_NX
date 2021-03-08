#include "download.hpp"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void downloadFile(const char *url, const char *filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);

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

    return;
}

std::string getLatestTag(std::string url) {
    downloadFile(url.c_str(), JSON_DOWNLOAD_PATH);

    json api_data;
    std::ifstream api_file(JSON_DOWNLOAD_PATH);

    api_file >> api_data;
    api_file.close();

    return api_data["tag_name"];
}

std::string getLatestDownload(std::string url) {
    const char *full_filename = JSON_DOWNLOAD_PATH;
    downloadFile(url.c_str(), full_filename);

    json api_data;
    std::ifstream api_file(JSON_DOWNLOAD_PATH);

    api_file >> api_data;
    api_file.close();

    std::string downloadURL;

    for (auto& array : api_data["assets"])
        downloadURL = array["browser_download_url"];
    return downloadURL;
}