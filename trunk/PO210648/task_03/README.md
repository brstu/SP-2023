# Лабораторная работа №3 DLL: динамически загружаемые библиотеки #

## Цель работы: Научиться создавать простейшие DLL. ##

### Задание ###

*** Создать библиотеку, считающую энтропию введённого слова ***

1. Создание DLL Файла: 
```c++
#include "entropyCalculator.h"
#include <cmath>

double calculateEntropy(const char* word) {
    int frequencies[256] = { 0 };
    int total = 0;
    const char* ptr = word;

    while (*ptr) {
        frequencies[(unsigned char)(*ptr)]++;
        total++;
        ptr++;
    }

    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            double probability = (double)frequencies[i] / total;
            entropy -= probability * log2(probability);
        }
    }

    return entropy;
}
```


 
```c++
#ifndef ENTROPY_CALCULATOR_H
#define ENTROPY_CALCULATOR_H

#ifdef _WIN32
#define DLLExport __declspec(dllexport)
#else
#define DLLExport
#endif

extern "C" DLLExport double calculateEntropy(const char* word); 
#endif // ENTROPY_CALCULATOR_H
  ```

2. Основной код:

```c++
#include <iostream>
#include <Windows.h>

int main() {
    HMODULE hModule = LoadLibrary(L"test1.dll");
    if (hModule == NULL) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    typedef double (*CalculateEntropyFunc)(const char*);
    CalculateEntropyFunc calculateEntropy = (CalculateEntropyFunc)GetProcAddress(hModule, "calculateEntropy");
    if (calculateEntropy == NULL) {
        std::cerr << "Failed to find function" << std::endl;
        FreeLibrary(hModule);
        return 1;
    }

    const char* word = "abracadabra";
    double entropy = calculateEntropy(word);
    std::cout << "Entropy: '" << word << "': " << entropy << std::endl;

    FreeLibrary(hModule);
    return 0;
}
```

3. Результат:

![1.jpg](images/1.jpg)

### Вывод ###

***Научился создавать простейшие DLL.***
