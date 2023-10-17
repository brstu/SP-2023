#pragma once
#include <iostream>
//#include "pch.h"

class Item {
public:
    Item(int id, double cost, double weight, int durability, int age);

    double CalculateCostPerGram() const;

    int CalculateRemainingLifetime() const;

    void Show() const;

private:
    int id;
    int durability;
    int age;
    double cost;
    double weight;
};
