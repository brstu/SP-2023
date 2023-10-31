#pragma once

#include <iostream>
#include <cmath>
#include <unordered_map>
#include "./Entropy.h"


    double EntropyCalculator::calculateEntropy(const std::string& word) const{
    std::unordered_map<char, int> charCounts;
    int totalChars = 0;

    for (char c : word) {
        charCounts[c]++;
        totalChars++;
    }

    double entropy = 0.0;

    for (const auto& [key,value] : charCounts) {
        double probability = static_cast<double> (value) / totalChars;
        entropy -= probability * log2(probability);
    }



        return entropy;
}