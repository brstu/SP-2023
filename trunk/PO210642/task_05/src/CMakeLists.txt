cmake_minimum_required(VERSION 3.5)

project(task_05)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(po8_210642_task_05.atomic
        Atomic.cpp
)

add_executable(po8_210642_task_05.mutex
        Mutex.cpp
)