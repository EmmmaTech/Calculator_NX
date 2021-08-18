#pragma once

#include <string>

bool downloadFile(const std::string &url, const std::string &filename);

std::string getLatestTag(int nightly);
std::string getLatestDownload(int nightly);