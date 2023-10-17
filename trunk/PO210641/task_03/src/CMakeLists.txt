cmake_minimum_required(VERSION 3.5)

project(task_03)

add_executable(po8_210641_task_03
        ConsoleApplication.cpp
)

add_library(mylib SHARED Item.cpp)

target_link_libraries(po8_210641_task_03 mylib)