//Реализация через атомные перееменные
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

//Реализация через мьютексы

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <string>
//
//std::string sharedString;
//std::mutex stringMutex;
//
//void InputThread(int threadNumber) {
//    std::string input;
//    std::string prompt = (threadNumber == 1) ? "Enter the first string: " : "Enter the second string: ";
//    std::cout << prompt;
//    std::getline(std::cin, input);
//
//    stringMutex.lock();
//    sharedString += input;
//    stringMutex.unlock();
//}
//
//int main() {
// 
//    std::thread thread1(InputThread, 1);
//    thread1.join();
//
//    std::thread thread2(InputThread, 2);
//    thread2.join();
//
//    stringMutex.lock();
//    std::cout << "Combined string: " << sharedString << std::endl;
//    stringMutex.unlock();
//
//    return 0;
//}


