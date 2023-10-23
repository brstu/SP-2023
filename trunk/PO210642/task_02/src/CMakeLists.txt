cmake_minimum_required(VERSION 3.5)

project(task_02)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210642_task_02
        SP_lab_2.cpp
)

target_link_libraries(po8_210642_task_02)