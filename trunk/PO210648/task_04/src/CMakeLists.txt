cmake_minimum_required(VERSION 3.5)

project(task_04)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210648_task_04 
        main.cpp
)
