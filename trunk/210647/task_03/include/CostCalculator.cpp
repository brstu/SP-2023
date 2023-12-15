#include "CostCalculator.h"

CostCalculator::CostCalculator (int id, int durability, int age, double cost, double weight)//210647
	: id(id), durability(durability), age(age), cost(cost), weight(weight) {//210647
}

double CostCalculator::CalculateCostPerGram() const//210647
{
    return cost / weight;//210647
}

int CostCalculator::CalculateRemainingLifetime() const//210647
{
    return durability - age;//210647
}

void CostCalculator::Show() const//210647
{
    std::cout << "Id: " << id << "\n";//210647
    std::cout << "Cost: $" << cost << "\n";//210647
    std::cout << "Weight: " << weight << " grams\n";//210647
    std::cout << "Durability: " << durability << " years\n";//210647
    std::cout << "Age: " << age << " years\n";//210647
}
