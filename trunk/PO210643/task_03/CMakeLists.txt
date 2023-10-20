cmake_minimum_required(VERSION 3.5)

project(task_03)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210643_task_03
        src/main.cpp
)

add_library(entropy SHARED include/Entropy.cpp)

target_link_libraries(po8_210643_task_03 entropy)