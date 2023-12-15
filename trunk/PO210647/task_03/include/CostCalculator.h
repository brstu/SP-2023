#pragma once
#include <iostream>

class CostCalculator {
public:
    CostCalculator(int id, int durability, int age, double cost, double weight);//1

    CostCalculator() = default;//1

    double CalculateCostPerGram() const;//1

    int CalculateRemainingLifetime() const;//1

    void Show() const;//1

private:
    int id = 1;//1
    int durability = 5;//1
    int age = 3;//1
    double cost = 10;//1
    double weight = 2;//1
};
