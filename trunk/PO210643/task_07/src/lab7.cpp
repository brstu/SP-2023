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
    Trader(const std::string& name) : name(name) {}
    void serveClients(Trader* otherTrader1, Trader* otherTrader2);
    void addClient(const Client& client);
    const std::string& getName() { return name; }

private:
    std::string name;
    std::queue<Client> clientsQueue;
    std::mutex queueMutex;
    std::condition_variable queueCondition;
};

void Trader::serveClients(Trader* otherTrader1, Trader* otherTrader2) {
while (true) {
        std::unique_lock<std::mutex> lock(queueMutex);

        Client client;
        if (!clientsQueue.empty()) {
            client = clientsQueue.front();
            clientsQueue.pop();
            lock.unlock();
            {

                std::unique_lock<std::mutex> outputLock(queueMutex);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));

                cout << ANSI_BOLD << "\033[93m" << name << ANSI_RESET
                    << " is starting to serve " << ANSI_BOLD << "\033[91m" << client.name << ANSI_RESET
                    << " for " << client.serviceTime << " seconds" << endl;


            }

            std::this_thread::sleep_for(std::chrono::seconds(client.serviceTime));

            {
                std::unique_lock<std::mutex> outputLock(queueMutex);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));


                cout << ANSI_BOLD << "\033[92m" << name << ANSI_RESET
                    << " finished serving " << ANSI_BOLD << "\033[91m" << client.name << ANSI_RESET << endl;
            }
        }
        else
        {
            lock.unlock();


            std::unique_lock<std::mutex> otherLock1(otherTrader1->queueMutex);
            if (!otherTrader1->clientsQueue.empty()) {
                Client otherClient = otherTrader1->clientsQueue.front();
                otherTrader1->clientsQueue.pop();
                otherLock1.unlock();

                {
                    std::unique_lock<std::mutex> outputLock(queueMutex);
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));

                    cout << ANSI_BOLD << "\033[93m" << name << ANSI_RESET
                        << " is starting to serve " << ANSI_BOLD << "\033[91m" << otherTrader1->getName() << ANSI_RESET
                        << " client " << ANSI_BOLD << "\033[91m" << otherClient.name << ANSI_RESET
                        << " for " << otherClient.serviceTime << " seconds" << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(otherClient.serviceTime));

                {
                    std::unique_lock<std::mutex> outputLock(queueMutex);

                    cout << ANSI_BOLD << "\033[92m" << name << ANSI_RESET
                        << " finished serving " << ANSI_BOLD << "\033[91m" << otherClient.name << ANSI_RESET << endl;
                }
            }
            else {
                otherLock1.unlock();
            }

            std::unique_lock<std::mutex> otherLock2(otherTrader2->queueMutex);
            if (!otherTrader2->clientsQueue.empty()) {
                Client otherClient = otherTrader2->clientsQueue.front();
                otherTrader2->clientsQueue.pop();
                otherLock2.unlock();

                {
                    std::unique_lock<std::mutex> outputLock(queueMutex);


                    cout << ANSI_BOLD << "\033[93m" << name << ANSI_RESET
                        << " is starting to serve " << ANSI_BOLD << "\033[91m" << otherTrader2->getName() << ANSI_RESET
                        << " client " << ANSI_BOLD << "\033[91m" << otherClient.name << ANSI_RESET
                        << " for " << otherClient.serviceTime << " seconds" << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(otherClient.serviceTime));

                {
                    std::unique_lock<std::mutex> outputLock(queueMutex);

                    cout << ANSI_BOLD << "\033[92m" << name << ANSI_RESET
                        << " finished serving " << ANSI_BOLD << "\033[91m" << otherClient.name << ANSI_RESET << endl;
                }
            }
            else {
                otherLock2.unlock();
            }
        }




    }
}


void Trader::addClient(const Client& client) {
    std::unique_lock<std::mutex> lock(queueMutex);
    clientsQueue.push(client);
    lock.unlock();
    queueCondition.notify_one();
}

int main() {
    Trader trader1("Trader1");
    Trader trader2("Trader2");
    Trader trader3("Trader3");


    std::thread thread3(&Trader::serveClients, &trader3, &trader2, &trader1);
    std::thread thread2(&Trader::serveClients, &trader2, &trader1, &trader3);
    std::thread thread1(&Trader::serveClients, &trader1, &trader2, &trader3);

    ifstream file("data.txt");
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            string name, time, trade;

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
