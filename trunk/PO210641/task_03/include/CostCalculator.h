#pragma once
#include <iostream>

class CostCalculator {
public:
    CostCalculator(int id, int durability, int age, double cost, double weight);

    CostCalculator() = default;

    double CalculateCostPerGram() const;

    int CalculateRemainingLifetime() const;

    void Show() const;

private:
    int id = 1;
    int durability = 5;
    int age = 3;
    double cost = 10;
    double weight = 2;
};
