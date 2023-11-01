# Лабораторная работа №3 #

## DLL: динамически загружаемые библиотеки ##

### Цель работы ###

Научиться создавать простейшие DLL.

Для выполнения лабораторной работы рекомендуется использовать Microsoft Visual Studio (Community Edition). Необходимо написать DLL согласно варианту и используя язык C++. Полученную DLL необходимо встроить в программу (рекомендуется использовать консольное приложение). Отчёт должен содержать цель работы, код программы и самой DLL, скриншот работы программы и вывод по лабораторной работе.

Для создания DLL в Microsoft Visual Studio вам необходимо создать новый проект и выбрав из списка шаблонов «Библиотека динамической компоновки DLL».

После создания шаблона DLL добавьте header в проект (Проект -> Добавить новый элемент… -> Файл заголовка (.h)). В него помещайте код, который будет вызываться в проекте. Затем создайте новый проект, из которого и будете вызывать созданную DLL. Для добавления её в проект необходимо перейти в «свойства» (иконка гаечного ключа в обозревателе решений), затем перейти в раздел C/C++ -> Общие и в пункте «Дополнительные каталоги включаем» выбрать путь к созданному h-файлу. После этого необходимо добавить его в необходимый файл проекта в коде через #include "*имя файла*.h"

## Сборка динамической библиотеки с CMake ##

Файл CMakeLists.txt добавляем в каталог task_03, файлы библиотеки в `/task_03/include`, остальные исходники в  `/task_03/src`

Далее в CMakeLists.txt прописываем

```CMake
# Добавляем исходные файлы
add_library(mylib SHARED mylib.cpp)
```

Параметр `SHARED` указывает на то, что библиотека динамическая. После добавления файлов библиотеки, нужно прилинковать их к исполняемому файлу.

```CMake
target_link_libraries(po8_21***_task_03 mylib)
```

Для ОС Windows необходимо устанавливать параметр

```CMake
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
```

## Добавление googletest ##

Для того, чтобы добавить `googletest`  необходимо открыть терминал перейти в каталог с task_03 и ввести следующие команды

```bash
git submodule add git@github.com:google/googletest.git
git submodule init
git submodule update
```

После чего подключить библиотеку в CMakeLists.txt. Файлы с тестами будут должны храниться в `/task_03/test`.

```CMake
add_subdirectory(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(main_test ${TEST_SRC_FILES})

target_link_libraries(main_test gtest gtest_main)

target_link_libraries(main_test mylib)

add_test(UnitTests main_test)
```

В `task_03/test` добавить 2 файла .h и .cpp.

В .h  подключить

```C++
#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mylib.h"
```

Общий вид CMakeLists.txt

```CMake
cmake_minimum_required(VERSION 3.5)

project(task_03)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
 set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
 set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)
 set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()

add_executable(po8_21***_task_03
        src/main.cpp
)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

add_library(mylib SHARED include/mylib.cpp)

target_link_libraries(po8_210***_task_03 mylib)

add_subdirectory(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(main_test ${TEST_SRC_FILES})

target_link_libraries(main_test gtest gtest_main gmock gmock_main)

target_link_libraries(main_test mylib)

add_test(UnitTests main_test)
```

### Варианты заданий ###

1. Создать библиотеку с классом *Item.* В классе *Item* должны быть поля *id, cost, weight, durability и age*. В классе также должен быть конструктор и методы для подсчёта стоимости на грамм, подсчёта ”оставшегося времени существования” (*durability* $-$ *age*) и вывода всех полей в консоль. В основной программе необходимо создать три объекта этого класса и провести с ними все возможные процедуры.
2. Создать библиотеку, сортирующую массив по убыванию и возрастанию, а также находящую максимум/минимум в массиве (реализовать всё отдельными функциями).
3. Создать библиотеку, считающую энтропию введённого слова.
4. Создать библиотеку, решающую квадратные уравнения.
5. Создать библиотеку, считающую площади треугольника, квадрата, круга и трапеции (реализовать всё отдельными функциями).
6. Реализовать два класса SportCar и Truck. Создать объекты обоих классов и вывести их параметры и рассчитать их эффективность. Реализовать подсчёт эффективности по-разному для разных классов.
7. Создать библиотеку, считающую количество указанных символов в тексте, а также находящую самый часто встречающийся символ.
