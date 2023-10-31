#include "CostCalculator.h"

CostCalculator::CostCalculator (int id, int durability, int age, double cost, double weight)
	: id(id), durability(durability), age(age), cost(cost), weight(weight) {
}

double CostCalculator::CalculateCostPerGram() const
{
    return cost / weight;
}

int CostCalculator::CalculateRemainingLifetime() const
{
    return durability - age;
}

void CostCalculator::Show() const
{
    std::cout << "Id: " << id << "\n";
    std::cout << "Cost: $" << cost << "\n";
    std::cout << "Weight: " << weight << " grams\n";
    std::cout << "Durability: " << durability << " years\n";
    std::cout << "Age: " << age << " years\n";
}
