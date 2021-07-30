#pragma once

#include <string>

bool downloadFile(const std::string &url, const std::string &filename);

std::string getLatestTag(bool nightly);
std::string getLatestDownload(bool nightly);