#pragma once

#include <json.hpp>
#include <sys/select.h>
#include <curl/curl.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include <stdio.h>
#include "constants.hpp"

#define API_AGENT "EmreTech"
using json = nlohmann::json;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
void downloadFile(const char *url, const char *filename);
std::string getLatestTag(std::string url);
std::string getLatestDownload(std::string url);