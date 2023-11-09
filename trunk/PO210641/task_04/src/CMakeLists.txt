cmake_minimum_required(VERSION 3.5)

project(task_04)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(po8_210641_task_04
        Main.cpp
        GameWindow.cpp 
        GuessNumberGameWindow.cpp
        GuessNumberSettings.cpp
        GuessNumberSettings.cpp
        RockPaperScissorsGameWindow.cpp
        RockPaperScissorsSettings.cpp
        Settings.cpp
        Window.cpp
)

target_link_libraries(po8_210641_task_04)