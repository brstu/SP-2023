
#include <iostream>
#include "../include/Entropy.h"
using namespace std;

int main() {
    string word;
    cout << "Enter word: ";
    cin >> word;
    auto entropy = new EntropyCalculator();
    double value = entropy->calculateEntropy(word);

    cout << "Entropy: " << value << endl;
    return 0;
}