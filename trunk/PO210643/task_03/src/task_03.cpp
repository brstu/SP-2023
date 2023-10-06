#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    string word;
    cout << "Enter word: ";
    cin >> word;
    double entropy = EntropyCalculator::calculateEntropy(word);
    cout << "Entropy: " << entropy << endl;
    return 0;
}
