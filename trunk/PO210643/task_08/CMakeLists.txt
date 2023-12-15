cmake_minimum_required(VERSION 3.5)

project(task_08)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(po8_210643_task_08_winapi
        src/WindowsProject1.cpp
        src/WindowsProject1.rc
   )
add_executable(po8_210643_task_08_main
        src/main.cpp
   )

add_library(hospitalDLL SHARED include/hospitalDLL.cpp "include/hospitalDLL.cpp")

target_link_libraries(po8_210643_task_08_main hospitalDLL)