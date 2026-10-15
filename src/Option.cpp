#include "Option.h"
#include "ConsoleLog.h"
#include <filesystem>
#include <string>
#include <cstdlib>

namespace fs = std::filesystem;

void ErrorExit(const std::string str)
{
    Log(str,LOG_TYPE::ERROR);
    std::exit(-1);
}

unsigned long long StringToULL(const std::string num_str)
{
    unsigned long long  num = 0;
    for(char vir : num_str)
    {
        if(vir<'0'||vir>'9') ErrorExit("Illegal parameters following '-t/--time'");
        num*=10;
        num+=vir-'0';
    }
    return num;
}

Opt::Opt(const int argc, const char* argv[])
{
    _WorkDirPath = fs::current_path();
    if(argv[1][0]!='-')
    {
        _SourceFilePath = argv[1];
        _isUseCompiledProgram = 0;
    }
    for(int i = 1;i<argc;i++)
    {
        if(argv[i][0]=='-')
        {
            std::string option = argv[i];
            //单示例输入文件路径
            if(option == "-i"||option == "--input")
            {
                if(_isInputDir == -1) _isInputDir = 0;
                else 
                {
                    Log("Input example file redefinition",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-i/--input'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _InputFilePath = argv[i+1];
                i++;
                continue;
            }
            //示例输入文件目录
            if(option == "-I"|| option == "--input-dir")
            {
                if(_isInputDir == -1) _isInputDir = 1;
                else 
                {
                    Log("Input example file redefinition",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-I/--input-dir'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _InputFilesDir = argv[i+1];
                i++;
                continue;
            }
            //单示例输出文件路径
            if(option == "-o"|| option == "--output")
            {
                if(_isOutputDir==-1) _isOutputDir = 0;
                else
                {
                    Log("Output example file redefinition",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-o/--output'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _OutputFilePath = argv[i+1];
                i++;
                continue;
            }
            //示例输出文件目录
            if(option == "-O"|| option == "--output-dir")
            {
                if(_isOutputDir==-1) _isOutputDir = 1;
                else
                {
                    Log("Output example file redefinition",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-O/--output-dir'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _OutputFilePath = argv[i+1];
                i++;
                continue;
            }
            //使用已编译程序
            if(option == "-p" || option == "--program")
            {
                if(_isUseCompiledProgram == -1) _isUseCompiledProgram = 1;
                else
                {
                    Log("The source files defined for compilation", LOG_TYPE::ERROR);
                    std::exit(-1);

                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-p/--program'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _CompiledProgram = argv[i+1];
                i++;
                continue;
            }
            //源文件编译
            if(option == "-c" || option == "--complied")
            {
                if(_isUseCompiledProgram == -1) _isUseCompiledProgram = 0;
                else
                {
                    Log("'-c/--complied' parameter error", LOG_TYPE::ERROR);
                    std::exit(-1);

                }
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-c/--complied'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _SourceFilePath = argv[i+1];
                i++;
                continue;
            }
            //编译输出路径
            if(option == "-b" || option == "--build")
            {
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-b/--build'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                _CompiledProgramOutputPath = argv[i+1];
                i++;
                continue;
            }
            //时间限制
            if(option == "-t" || option == "--time")
            {
                if(argv[i+1][0]=='-') 
                {
                    Log("Unknown argument after '-t/--time'",LOG_TYPE::ERROR);
                    std::exit(-1);
                }
                std::string time_str = argv[i+1];
                _TimeLimit = StringToULL(time_str);
                _TimeLimit = true;
                i++;
                continue;
            }
            //内存限制
            if(option == "-s"|| option == "--space")
            {
                if(argv[i+1][0]=='-') ErrorExit("Unknown argument after '-s/--space'");
                std::string space_str = argv[i+1];
                _SpaceLimit = StringToULL(space_str);
                i++;
                continue;
            }
        }
        
    }
}
