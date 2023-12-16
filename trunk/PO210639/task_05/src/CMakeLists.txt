cmake_minimum_required(VERSION 3.5)

project(task_05)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(po8_210639_task_05.atomic
        lab5.atomic.cpp
)

add_executable(po8_210639_task_05.mutex
        lab5.mutex.cpp
)