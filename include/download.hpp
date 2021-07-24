#pragma once

#include <curl/curl.h>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#define API_AGENT "EmreTech"

CURLcode downloadFile(const std::string &url, const std::string &filename);

std::string getLatestTag(bool nightly);
std::string getLatestDownload(bool nightly);