#pragma once

#include <iostream>
#include <cmath>
#include <unordered_map>
#include "./Entropy.h"
using namespace std;


    double EntropyCalculator::calculateEntropy(const string& word) {
    unordered_map<char, int> charCounts;
    int totalChars = 0;

    for (char c : word) {
        charCounts[c]++;
        totalChars++;
    }

    double entropy = 0.0;

    for (const auto& pair : charCounts) {
    double probability = static_cast<double>(pair.second) / totalChars;
         entropy -= probability * log2(probability);
    }



        return entropy;
}