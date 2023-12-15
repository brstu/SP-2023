#pragma once
#include <iostream>

class CostCalculator {//210647
public:
    CostCalculator(int id, int durability, int age, double cost, double weight);//210647

    CostCalculator() = default;//210647

    double CalculateCostPerGram() const;//210647

    int CalculateRemainingLifetime() const;//210647

    void Show() const;//210647

private://210647
    int id = 1;//210647
    int durability = 5;//210647
    int age = 3;//210647
    double cost = 10;//210647
    double weight = 2;//210647
};
