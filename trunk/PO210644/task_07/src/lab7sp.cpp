#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Windows.h>
#include <ctime>



int i = 1;

class Waiter {
public:
    void TakeOrder(int orderNumber) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !isCooking_; });
        std::cout << "Waiter " << id_ << " took order " << orderNumber << std::endl;
        isCooking_ = true;
        cv_.notify_all();
    }

    void ServeOrder(int orderNumber) {
        int random = (500 + rand() % 5000);
        Sleep(random);
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return isCooking_; });
        std::cout << "Waiter " << id_ << " served order " << orderNumber << " in " << (double)random/1000  << std::endl;
        isCooking_ = false;
        cv_.notify_all();
    }
    void setid(int id) {
        id_ = id;
    }

private:
    int id_;
    bool isCooking_ = false;
    std::mutex mutex_;
    std::condition_variable cv_;
};

class Chef {
public:
    void CookOrder(int orderNumber) {
        int random = (500 + rand() % 10000);
        Sleep(random);
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !isBusy_; });
        std::cout << "Chef cooked order " << orderNumber << " via " << (double)random/1000 << "sec" << std::endl;
        isBusy_ = true;
        cv_.notify_all();
    }

    void FinishOrder(int orderNumber) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return isBusy_; });
        std::cout << "Chef finished order " << orderNumber << "and started cooking " << orderNumber + 1 << std::endl;
        isBusy_ = false;
        cv_.notify_all();
    }

private:
    bool isBusy_ = false;
    std::mutex mutex_;
    std::condition_variable cv_;
};

int main() {
    srand(time(0));
    Waiter waiter1, waiter2, waiter3;
    Chef chef;
    waiter1.setid(1);
    waiter2.setid(2);
    waiter3.setid(3);

    std::thread waiterThread1([&waiter1] { waiter1.TakeOrder(i); });
    
    
    
    std::thread waiterThread2([&waiter2] { waiter2.TakeOrder(i + 1); });
    
    std::thread waiterThread3([&waiter3] { waiter3.TakeOrder(i + 2); });
    
    std::thread chefThread([&chef] { chef.CookOrder(i); });
    chef.FinishOrder(i);
    waiter1.ServeOrder(i);
    waiter1.TakeOrder(i + 3);

    chef.CookOrder(i + 1);
    chef.FinishOrder(i + 1);
    waiter2.ServeOrder(i + 1);
    waiter2.TakeOrder(i + 4);

    chef.CookOrder(i + 2);
    chef.FinishOrder(i + 2);
    waiter3.ServeOrder(i + 2);
    waiter3.TakeOrder(i + 5);

    
    
    
   
   


    
    for(i = 4; i < 20; i += 3){
        srand(time(0));

        chef.CookOrder(i);
        chef.FinishOrder(i);
        waiter1.ServeOrder(i);
        waiter1.TakeOrder(i + 3);
        
        chef.CookOrder(i + 1);
        chef.FinishOrder(i + 1);
        waiter2.ServeOrder(i + 1);
        waiter2.TakeOrder(i + 4);
        
        chef.CookOrder(i + 2);
        chef.FinishOrder(i + 2);
        waiter3.ServeOrder(i + 2);
        waiter3.TakeOrder(i + 5);
        
        
        

        
    }
    std::cout << "All Orders are done. Good job!" << std::endl;
    waiterThread1.join();
    waiterThread2.join();
    waiterThread3.join();
    chefThread.join();
    return 0;
}
