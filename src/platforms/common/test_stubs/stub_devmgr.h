#pragma once

#include "DevMgr.hpp"

#include <functional>

std::function<int(unsigned int &, const char **)> stub_getNextDeviceName_callback;
