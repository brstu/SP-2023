#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random> 
#include <chrono>

class Restaurant {//1
public://1
    void Run() {//1
        CreateNamesFile();//1

        std::ifstream namesFile("names.txt");//1

        if (namesFile.is_open()) {//1
            if (std::getline(namesFile, waiter1Name_)) {//1
                waiter1_.SetName(waiter1Name_);//1
            }//1
            if (std::getline(namesFile, waiter2Name_)) {//1
                waiter2_.SetName(waiter2Name_);//1
            }//1
            if (std::getline(namesFile, waiter3Name_)) {//1
                waiter3_.SetName(waiter3Name_);//1
            }//1
            if (std::getline(namesFile, chefName_)) {//1
                chef_.SetName(chefName_);//1
            }

            namesFile.close();//1
        }//1
        else {//1
            std::cerr << "Unable to open names.txt file!" << std::endl;//1
            return;//1
        }//1

        std::jthread waiterThread1([this] { waiter1_.AcceptOrder(i_); });//1
        std::jthread waiterThread2([this] { waiter2_.AcceptOrder(i_ + 1); });//1
        std::jthread waiterThread3([this] { waiter3_.AcceptOrder(i_ + 2); });//1
        std::jthread chefThread([this] { chef_.CookOrder(i_); });//1

        chef_.CompleteOrder(i_);//1
        waiter1_.ServeOrder(i_);//1
        waiter1_.AcceptOrder(i_ + 3);//1

        chef_.CookOrder(i_ + 1);//1
        chef_.CompleteOrder(i_ + 1);//1
        waiter2_.ServeOrder(i_ + 1);//1
        waiter2_.AcceptOrder(i_ + 4);//1

        chef_.CookOrder(i_ + 2);//1
        chef_.CompleteOrder(i_ + 2);//1
        waiter3_.ServeOrder(i_ + 2);//1
        waiter3_.AcceptOrder(i_ + 5);//1

        for (i_ = 4; i_ < 20; i_ += 3) {//1
            chef_.CookOrder(i_);//1
            chef_.CompleteOrder(i_);//1
            waiter1_.ServeOrder(i_);//1
            waiter1_.AcceptOrder(i_ + 3);//1

            chef_.CookOrder(i_ + 1);//1
            chef_.CompleteOrder(i_ + 1);//1
            waiter2_.ServeOrder(i_ + 1);//1
            waiter2_.AcceptOrder(i_ + 4);//1

            chef_.CookOrder(i_ + 2);//1
            chef_.CompleteOrder(i_ + 2);//1
            waiter3_.ServeOrder(i_ + 2);//1
            waiter3_.AcceptOrder(i_ + 5);//1
        }//1

        std::cout << "All Orders are done. Good job!" << std::endl;//1

        waiterThread1.join();//1
        waiterThread2.join();//1
        waiterThread3.join();//1
        chefThread.join();//1
    }//1

private://1
    int i_ = 1;//1

    void CreateNamesFile() {//1
        std::ofstream namesFile("names.txt");//1
        if (namesFile.is_open()) {//1
            namesFile << "Vasya\n";//1
            namesFile << "Bob\n";//1
            namesFile << "Charlie\n";//1
            namesFile << "David\n";//1
            namesFile.close();//1
        }//1
        else {//1
            std::cerr << "Unable to create names.txt file!" << std::endl;//1
        }//1
    }//1

    class Waiter {//1
    public://1
        void AcceptOrder(int orderNumber) {//1
            std::unique_lock lock(mutex_);//1
            cv_.wait(lock, [this] { return !isCooking_; });//1
            std::cout << "Waiter " << name_ << " took order " << orderNumber << std::endl;//1
            isCooking_ = true;//1
            cv_.notify_all();//1
        }//1

        void ServeOrder(int orderNumber) {//1
            std::chrono::milliseconds random(500 + distribution_(generator_));//1
            std::this_thread::sleep_for(random);//1
            std::unique_lock lock(mutex_);//1
            cv_.wait(lock, [this] { return isCooking_; });//1
            std::cout << "Waiter " << name_ << " served order " << orderNumber << " in " << static_cast<double>(random.count()) / 1000 << " sec" << std::endl;//1
            isCooking_ = false;//1
            cv_.notify_all();//1
        }//1

        void SetName(const std::string_view& name) {//1
            name_ = name;//1
        }//1

    private://1
        std::string name_;//1
        bool isCooking_ = false;//1
        std::mutex mutex_;//1
        std::condition_variable cv_;//1
        std::random_device generator_;//1
        std::uniform_int_distribution<> distribution_{ 0, 5000 };//1
    };//1

    class Chef {//1
    public://1
        void CookOrder(int orderNumber) {//1
            std::chrono::milliseconds random(500 + distribution_(generator_));//1
            std::this_thread::sleep_for(random);//1
            std::unique_lock lock(mutex_);//1
            cv_.wait(lock, [this] { return !isBusy_; });//1
            std::cout << "Chef " << name_ << " cooked order " << orderNumber << " via " << static_cast<double>(random.count()) / 1000 << " sec" << std::endl;//1
            isBusy_ = true;//1
            cv_.notify_all();//1
        }//1

        void CompleteOrder(int orderNumber) {//1
            std::unique_lock lock(mutex_);//1
            cv_.wait(lock, [this] { return isBusy_; });//1
            std::cout << "Chef " << name_ << " finished order " << orderNumber << " and started cooking order " << orderNumber + 1 << std::endl;//1
            isBusy_ = false;//1
            cv_.notify_all();//1
        }//1

        void SetName(const std::string_view& name) {//1
            name_ = name;//1
        }//1

    private:
        std::string name_;//1
        bool isBusy_ = false;//1
        std::mutex mutex_;//1
        std::condition_variable cv_;//1
        std::random_device generator_;//1
        std::uniform_int_distribution<> distribution_{ 0, 10000 };//1
    };//1

    Waiter waiter1_;//1
    Waiter waiter2_;//1
    Waiter waiter3_;//1
    Chef chef_;//1

    std::string waiter1Name_;//1
    std::string waiter2Name_;//1
    std::string waiter3Name_;//1
    std::string chefName_;//1
};

int main() {//1
    Restaurant restaurant;//1
    restaurant.Run();//1

    return 0;//1
}
