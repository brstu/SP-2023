cmake_minimum_required(VERSION 3.5)

project(task_05)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210641_task_05.atomic
        AtomicCombinedString.cpp
)

target_link_libraries(po8_210641_task_05.atomic)

add_executable(po8_210641_task_05.mutex
        MutexCombinedString.cpp
)

target_link_libraries(po8_210641_task_05.mutex)

