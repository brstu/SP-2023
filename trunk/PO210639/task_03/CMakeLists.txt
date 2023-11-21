cmake_minimum_required(VERSION 3.5)

project(task_03)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(po8_210639_task_03
        src/main.cpp
)

add_library(SortAndFindMinMax SHARED include/SortAndFindMinMax.cpp)

target_link_libraries(po8_210639_task_03 SortAndFindMinMax)

add_subdirectory(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(main_test ${TEST_SRC_FILES})

target_link_libraries(main_test gtest gtest_main gmock gmock_main)

target_link_libraries(main_test SortAndFindMinMax)


add_test(UnitTests main_test)