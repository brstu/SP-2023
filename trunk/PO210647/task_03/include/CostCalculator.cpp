#include "CostCalculator.h"

CostCalculator::CostCalculator (int id, int durability, int age, double cost, double weight)//1
	: id(id), durability(durability), age(age), cost(cost), weight(weight) {//1
}

double CostCalculator::CalculateCostPerGram() const//1
{
    return cost / weight;//1
}

int CostCalculator::CalculateRemainingLifetime() const//1
{
    return durability - age;//1
}

void CostCalculator::Show() const//1
{
    std::cout << "Id: " << id << "\n";//1
    std::cout << "Cost: $" << cost << "\n";//1
    std::cout << "Weight: " << weight << " grams\n";//1
    std::cout << "Durability: " << durability << " years\n";//1
    std::cout << "Age: " << age << " years\n";//1
}
