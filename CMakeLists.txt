cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(bu
    VERSION 1.0
    LANGUAGES CXX
)

if(WIN32)
    add_executable(AutoTestManager
        src/Main.cpp
        src/Option.cpp
        res/icon.o
    )
elseif(LINUX)
    add_executable(AutoTestManager
        src/Main.cpp
        src/Option.cpp
    )
endif()

target_include_directories(AutoTestManager
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(AutoTestManager
    PRIVATE
        cxx_std_17
)

target_link_options(AutoTestManager
    PRIVATE
        -static
        -static-libgcc
        -static-libstdc++
)

set_target_properties(AutoTestManager PROPERTIES OUTPUT_NAME "atm")