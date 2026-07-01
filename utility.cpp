#include "utility.h"

#include <ctime>
#include <sstream>
#include <iomanip>

std::string CurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm tmVal{};

#if defined(_WIN32)
    localtime_s(&tmVal, &t);
#else
    localtime_r(&t, &tmVal);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tmVal, "%Y-%m-%d");
    return oss.str();
}