#pragma once
#include <filesystem>
#include <string>

class Opt
{
private:
    std::filesystem::path _SelfPath;
    bool _isInputDir;
    std::filesystem::path _InputFilePath;
    std::filesystem::path _InputFilesDir;
    bool _isOutputDir;
    std::filesystem::path _OutputFilePath;
    std::filesystem::path _OutputFilesDir;
    bool _isUseCompiledProgram;
    std::filesystem::path _CompiledProgram;
    std::filesystem::path _SourceFilePath;
    std::filesystem::path _CompiledProgramOutputPath;
    bool _isEnableTimeLimit;
    unsigned long long _TimeLimit;
    bool _isEnableSpaceLimit;
    unsigned long long _SpaceLimit;
public:
    void SetSelfPath(std::string SelfPath);
    void SetInputMode(bool _isInputDir);
    Opt(const char* argv[]);
};