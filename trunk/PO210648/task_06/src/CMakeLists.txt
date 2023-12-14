cmake_minimum_required(VERSION 3.5)

project(task_06)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(po8_210648_task_06
        main.cpp
)