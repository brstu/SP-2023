cmake_minimum_required(VERSION 3.5)

project(task_07)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(po8_210643_task_07
        src/lab7.cpp
)

