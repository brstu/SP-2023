#include "item.h"
#include "item.h"

Item::Item (int id, double cost, double weight, int durability, int age)
	: id(id), cost(cost), weight(weight), durability(durability), age(age) {
}

double Item::CalculateCostPerGram() const
{
    return cost / weight;
}

int Item::CalculateRemainingLifetime() const
{
    return durability - age;
}

void Item::Show() const
{
    std::cout << "Id: " << id << "\n";
    std::cout << "Cost: $" << cost << "\n";
    std::cout << "Weight: " << weight << " grams\n";
    std::cout << "Durability: " << durability << " years\n";
    std::cout << "Age: " << age << " years\n";
}



