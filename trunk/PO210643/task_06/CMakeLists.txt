cmake_minimum_required(VERSION 3.5)

project(task_06)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210643_task_06
        src/lab6.cpp
)

