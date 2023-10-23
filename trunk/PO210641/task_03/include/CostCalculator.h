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
    int durability = 1;
    int age = 1;
    double cost = 1;
    double weight = 1;
};
