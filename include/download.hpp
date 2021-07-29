#pragma once

#include <string>

void downloadFile(const std::string &url, const std::string &filename);

std::string getLatestTag(bool nightly);
std::string getLatestDownload(bool nightly);