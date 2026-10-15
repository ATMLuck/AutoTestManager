#include <string>
#include <iostream>
#include "ConsoleLog.h"
void Log(std::string str,LOG_TYPE str_type)
{
    switch(str_type)
    {
    case LOG_TYPE::STR:
        std::cout << str << std::endl;
        break;
    case LOG_TYPE::INFO:
        std::cout << "\033[34m" << "[INFO] " << str << "\033[0m" << std::endl;
        break;
    case LOG_TYPE::ERROR:
        std::cout << "\033[31;1m" << "[ERROR] " << str << "\033[0m" << std::endl;
        break;
    case LOG_TYPE::WARN:
        std::cout << "\033[33;1m" << "[WARN]" << str << "\033[0m" << std::endl;
        break;
    }
}