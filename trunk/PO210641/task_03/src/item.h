#pragma once
#include <iostream>
#include "pch.h"

class Item {
public:
    Item(int id, double cost, double weight, int durability, int age)
        : id(id), cost(cost), weight(weight), durability(durability), age(age) {
    }

    double CalculateCostPerGram() const {
        return cost / weight;
    }

    int CalculateRemainingLifetime() const {
        return durability - age;
    }

    void Show() const {
        std::cout << "Id: " << id << "\n";
        std::cout << "Cost: $" << cost << "\n";
        std::cout << "Weight: " << weight << " grams\n";
        std::cout << "Durability: " << durability << " years\n";
        std::cout << "Age: " << age << " years\n";
    }

private:
    int id;
    double cost;
    double weight;
    int durability;
    int age;
};
