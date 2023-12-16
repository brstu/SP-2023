#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random> 
#include <chrono>

class Restaurant {
public:
    void Run() {
        CreateNamesFile();

        std::ifstream namesFile("names.txt");

        if (namesFile.is_open()) {
            if (std::getline(namesFile, waiter1Name_)) {
                waiter1_.SetName(waiter1Name_);
            }
            if (std::getline(namesFile, waiter2Name_)) {
                waiter2_.SetName(waiter2Name_);
            }
            if (std::getline(namesFile, waiter3Name_)) {
                waiter3_.SetName(waiter3Name_);
            }
            if (std::getline(namesFile, chefName_)) {
                chef_.SetName(chefName_);
            }

            namesFile.close();
        }
        else {
            std::cerr << "Unable to open names.txt file!" << std::endl;
            return;
        }

        std::jthread waiterThread1([this] { waiter1_.AcceptOrder(i_); });
        std::jthread waiterThread2([this] { waiter2_.AcceptOrder(i_ + 1); });
        std::jthread waiterThread3([this] { waiter3_.AcceptOrder(i_ + 2); });
        std::jthread chefThread([this] { chef_.CookOrder(i_); });

        chef_.CompleteOrder(i_);
        waiter1_.ServeOrder(i_);
        waiter1_.AcceptOrder(i_ + 3);

        chef_.CookOrder(i_ + 1);
        chef_.CompleteOrder(i_ + 1);
        waiter2_.ServeOrder(i_ + 1);
        waiter2_.AcceptOrder(i_ + 4);

        chef_.CookOrder(i_ + 2);
        chef_.CompleteOrder(i_ + 2);
        waiter3_.ServeOrder(i_ + 2);
        waiter3_.AcceptOrder(i_ + 5);

        for (i_ = 4; i_ < 20; i_ += 3) {
            chef_.CookOrder(i_);
            chef_.CompleteOrder(i_);
            waiter1_.ServeOrder(i_);
            waiter1_.AcceptOrder(i_ + 3);

            chef_.CookOrder(i_ + 1);
            chef_.CompleteOrder(i_ + 1);
            waiter2_.ServeOrder(i_ + 1);
            waiter2_.AcceptOrder(i_ + 4);

            chef_.CookOrder(i_ + 2);
            chef_.CompleteOrder(i_ + 2);
            waiter3_.ServeOrder(i_ + 2);
            waiter3_.AcceptOrder(i_ + 5);
        }

        std::cout << "All Orders are done. Good job!" << std::endl;

        waiterThread1.join();
        waiterThread2.join();
        waiterThread3.join();
        chefThread.join();
    }

private:
    int i_ = 1;

    void CreateNamesFile() {
        std::ofstream namesFile("names.txt");
        if (namesFile.is_open()) {
            namesFile << "Vasya\n";
            namesFile << "Bob\n";
            namesFile << "Charlie\n";
            namesFile << "David\n";
            namesFile.close();
        }
        else {
            std::cerr << "Unable to create names.txt file!" << std::endl;
        }
    }

    class Waiter {
    public:
        void AcceptOrder(int orderNumber) {
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return !isCooking_; });
            std::cout << "Waiter " << name_ << " took order " << orderNumber << std::endl;
            isCooking_ = true;
            cv_.notify_all();
        }

        void ServeOrder(int orderNumber) {
            std::chrono::milliseconds random(500 + distribution_(generator_));
            std::this_thread::sleep_for(random);
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return isCooking_; });
            std::cout << "Waiter " << name_ << " served order " << orderNumber << " in " << static_cast<double>(random.count()) / 1000 << " sec" << std::endl;
            isCooking_ = false;
            cv_.notify_all();
        }

        void SetName(const std::string_view& name) {
            name_ = name;
        }

    private:
        std::string name_;
        bool isCooking_ = false;
        std::mutex mutex_;
        std::condition_variable cv_;
        std::random_device generator_;
        std::uniform_int_distribution<> distribution_{ 0, 5000 };
    };

    class Chef {
    public:
        void CookOrder(int orderNumber) {
            std::chrono::milliseconds random(500 + distribution_(generator_));
            std::this_thread::sleep_for(random);
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return !isBusy_; });
            std::cout << "Chef " << name_ << " cooked order " << orderNumber << " via " << static_cast<double>(random.count()) / 1000 << " sec" << std::endl;
            isBusy_ = true;
            cv_.notify_all();
        }

        void CompleteOrder(int orderNumber) {
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return isBusy_; });
            std::cout << "Chef " << name_ << " finished order " << orderNumber << " and started cooking order " << orderNumber + 1 << std::endl;
            isBusy_ = false;
            cv_.notify_all();
        }

        void SetName(const std::string_view& name) {
            name_ = name;
        }

    private:
        std::string name_;
        bool isBusy_ = false;
        std::mutex mutex_;
        std::condition_variable cv_;
        std::random_device generator_;
        std::uniform_int_distribution<> distribution_{ 0, 10000 };
    };

    Waiter waiter1_;
    Waiter waiter2_;
    Waiter waiter3_;
    Chef chef_;

    std::string waiter1Name_;
    std::string waiter2Name_;
    std::string waiter3Name_;
    std::string chefName_;
};

int main() {
    Restaurant restaurant;
    restaurant.Run();

    return 0;
}
