#pragma once

#define NON_COPYABLE(c) c(const c &) = delete; c &operator=(const c &) = delete;
#define NON_MOVABLE(c) c(c &&) = delete; c &operator=(c &&) = delete;