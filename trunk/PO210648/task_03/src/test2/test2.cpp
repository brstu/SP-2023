#include <iostream>
#include <Windows.h>
//#include "entropyCalculator.h"

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
