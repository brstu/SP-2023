#include <iostream>
#include <thread>
#include <atomic>
#include <string>

const int MaxChars = 100;
std::atomic<int> charIndex(0);
char sharedChars[MaxChars] = { 0 };

void InputThread(int threadNumber) {
    std::string input;
    std::cout << "Enter string " << threadNumber << ": ";
    std::getline(std::cin, input);

    for (char c : input) {
        int index = charIndex.fetch_add(1);
        if (index < MaxChars) {
            sharedChars[index] = c;
        }
        else {
            std::cerr << "Error: The maximum string length has been exceeded." << std::endl;
            break;
        }
    }
}

int main() {

    std::thread thread1(InputThread, 1);
    thread1.join();

    InputThread(2);

    std::cout << "Combined string: " << sharedChars << std::endl;

    return 0;
}