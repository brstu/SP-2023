#include <iostream>
#include <Windows.h>

int main() {
    HMODULE hModule = LoadLibrary(L"test1.dll");
    if (hModule == nullptr) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    using typedef double (*CalculateEntropyFunc)(const char*);
    auto calculateEntropy = (CalculateEntropyFunc)GetProcAddress(hModule, "calculateEntropy");
    if (calculateEntropy == nullptr) {
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
