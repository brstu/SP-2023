
#include <iostream>
#include "../include/Entropy.h"

int main() {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;
    auto entropy = std::make_unique<EntropyCalculator>();
    double value = entropy->calculateEntropy(word);
    
    std::cout << "Entropy: " << value << std::endl;
    return 0;
}
