#include <iostream>
#include <thread>
#include <atomic>
#include <string>

const int MaxChars = 10;

void InputThread(std::atomic<int>& charIndex, std::string& sharedString, int threadNumber) {
    std::string input;
    std::cout << "Enter string " << threadNumber << ": ";
    std::getline(std::cin, input);

    for (char c : input) {
        int index = charIndex.fetch_add(1);
        if (index < MaxChars) {
            sharedString += c;
        }
        else {
            std::cerr << "Error: The maximum string length has been exceeded." << std::endl;
            break;
        }
    }
}

int main() {
    std::string sharedString;

    std::atomic<int> charIndex(0);

    std::jthread thread1(InputThread, std::ref(charIndex), std::ref(sharedString), 1);
    thread1.join();

    std::jthread thread2(InputThread, std::ref(charIndex), std::ref(sharedString), 2);
    thread2.join();

    std::cout << "Combined string: " << sharedString << std::endl;

    return 0;
}