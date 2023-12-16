cmake_minimum_required(VERSION 3.5)

project(task_04)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(po8_210642_task_04
        main.cpp     
        Window.cpp
        Window.h
        WFile.cpp
        WFile.h
        WFolder.cpp
        WFolder.h
        FolderWindow.h
        FolderWindow.cpp
        FolderObject.h
)