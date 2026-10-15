#pragma once
#include <string>

enum LOG_TYPE
{
    STR,
    INFO,
    ERROR,
    WARN
};

void Log(std::string str, LOG_TYPE str_type);
