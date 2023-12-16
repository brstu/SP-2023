cmake_minimum_required(VERSION 3.5)

project(task_08)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(po8_210639_task_08_win32 WIN32
        src/winapi.cpp
        src/winapi.rc
)

add_executable(po8_210639_task_08_main
        src/main.cpp
)

add_library(hospitalLibrary SHARED include/hospitalLibrary.cpp)

target_link_libraries(po8_210639_task_08_main hospitalLibrary)
