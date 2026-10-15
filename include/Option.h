#pragma once
#include <filesystem>

class Opt
{
public:
    std::filesystem::path _WorkDirPath;
    int _isInputDir = -1;
    std::filesystem::path _InputFilePath = "./in.txt";
    std::filesystem::path _InputFilesDir = "./in/";
    int _isOutputDir = -1;
    std::filesystem::path _OutputFilePath = "./out.txt";
    std::filesystem::path _OutputFilesDir = "./out/";
    int _isUseCompiledProgram = -1;
    std::filesystem::path _CompiledProgram;
    std::filesystem::path _SourceFilePath;
    std::filesystem::path _CompiledProgramOutputPath = "./build/";
    bool _isEnableTimeLimit = false;
    unsigned long long _TimeLimit = 1000;
    bool _isEnableSpaceLimit = false;
    unsigned long long _SpaceLimit;

    Opt(const int argc, const char* argv[]);
};