#include "entropyCalculator.h"
#include <cmath>

double calculateEntropy(const char* word) {
    std::array<int, 256> frequencies;
    int total = 0;
    const char* ptr = word;

    while (*ptr) {
        frequencies[(unsigned char)(*ptr)]++;
        total++;
        ptr++;
    }

    double entropy = 0.0;
    std::ranges::for_each (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            double probability = (double)frequencies[i] / total;
            entropy -= probability * log2(probability);
        }
    }

    return entropy;
}
