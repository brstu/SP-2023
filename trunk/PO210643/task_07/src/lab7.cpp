#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const string ANSI_RESET = "\033[0m";
const string ANSI_BOLD = "\033[1m";
const string ANSI_RED = "\033[91m";
const string ANSI_GREEN = "\033[92m";

struct Client {
    int id;
    std::string name;
    int serviceTime;
};




class Trader {
public:
    explicit Trader(const std::string& name) : name(name) {}
    [[noreturn]] void serveClients(Trader* otherTrader1, Trader* otherTrader2);
    void addClient(const Client& client);
    const std::string& getName() const { return name; }
    void printServiceInfo(std::mutex& queueMutex, const std::string& name, const Client& client) {
        std::unique_lock outputLock(queueMutex);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        std::cout << "\033[1m\033[33m" << name << "\033[0m"
            << " is starting to serve " << "\033[1m\033[31m" << client.name << "\033[0m"
            << " for " << client.serviceTime << " seconds" << std::endl;
    }
    void printFinishedServiceInfo(std::mutex& queueMutex, const std::string& name, const std::string& clientName) {
        std::unique_lock outputLock(queueMutex);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        std::cout << "\033[1m\033[32m" << name << "\033[0m"
            << " finished serving " << "\033[1m\033[31m" << clientName << "\033[0m" << std::endl;
    }


private:
    std::string name;
    std::queue<Client> clientsQueue;
    std::mutex queueMutex;
    std::condition_variable queueCondition;
};


[[noreturn]] void Trader::serveClients (Trader* otherTrader1, Trader* otherTrader2) {
while (true) {
        std::unique_lock lock(queueMutex);
        Client client;
        if (!clientsQueue.empty()) {
            client = clientsQueue.front();
            clientsQueue.pop();
            lock.unlock();
            printServiceInfo(queueMutex, name, client)

            std::this_thread::sleep_for(std::chrono::seconds(client.serviceTime));

            printFinishedServiceInfo(queueMutex, name, client.name);

        }
        else
        {
            lock.unlock();


            std::unique_lock otherLock1(otherTrader1->queueMutex);
            if (!otherTrader1->clientsQueue.empty()) {
                Client otherClient = otherTrader1->clientsQueue.front();
                otherTrader1->clientsQueue.pop();
                otherLock1.unlock();

                printServiceInfo(queueMutex, name, otherClient);
                std::this_thread::sleep_for(std::chrono::seconds(otherClient.serviceTime));
                printFinishedServiceInfo(queueMutex, name, otherClient.name);

            }
            else {
                otherLock1.unlock();
            }

            std::unique_lock otherLock2(otherTrader2->queueMutex);
            if (!otherTrader2->clientsQueue.empty()) {
                Client otherClient = otherTrader2->clientsQueue.front();
                otherTrader2->clientsQueue.pop();
                otherLock2.unlock();

                printServiceInfo(queueMutex, name, otherClient);
                std::this_thread::sleep_for(std::chrono::seconds(otherClient.serviceTime));

                printFinishedServiceInfo(queueMutex, name, otherClient.name);

            }
            else {
                otherLock2.unlock();
            }
        }




    }
}


void Trader::addClient(const Client& client) {
    std::unique_lock lock(queueMutex);
    clientsQueue.push(client);
    lock.unlock();
    queueCondition.notify_one();
}

int main() {
    Trader trader1("Trader1");
    Trader trader2("Trader2");
    Trader trader3("Trader3");


    std::jthread thread3(&Trader::serveClients, &trader3, &trader2, &trader1);
    std::jthread thread2(&Trader::serveClients, &trader2, &trader1, &trader3);
    std::jthread thread1(&Trader::serveClients, &trader1, &trader2, &trader3);

    ifstream file("data.txt");
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            string name;
            string time;
            string trade;

            if (iss >> name >> time >> trade) {
                Client client;
                client.name = name;
                client.serviceTime = std::stoi(time);
                if (trade == "1") {
                    trader1.addClient(client);
                }
                else if (trade == "2") {
                    trader2.addClient(client);
                }
                else if (trade == "3") {
                    trader3.addClient(client);
                }
            }
        }
        file.close();
    }
    else {
        cerr << "Failed to open data.txt" << endl;
        return 1;
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));



    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
