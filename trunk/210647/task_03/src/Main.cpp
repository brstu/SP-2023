#include "../include./CostCalculator.h"

int main() {
    CostCalculator calculator1(1, 70.0, 100.0, 5, 1);//210647
    CostCalculator calculator2(2, 50.0, 65.0, 3, 2);//210647
    CostCalculator calculator3(3, 20.0, 40.0, 4, 3);//210647

    std::cout << "===== Calculator 1 =====" << "\n";//210647
    calculator1.Show();//210647
    std::cout << "Cost per gram: $" << calculator1.CalculateCostPerGram() << "\n";//210647
    std::cout << "Remaining lifetime: " << calculator1.CalculateRemainingLifetime() << " years\n";//210647
    std::cout << "\n";//210647

    std::cout << "===== Calculator 2 =====" << "\n";//210647
    calculator2.Show();//210647
    std::cout << "Cost per gram: $" << calculator2.CalculateCostPerGram() << "\n";//210647
    std::cout << "Remaining lifetime: " << calculator2.CalculateRemainingLifetime() << " years\n";//210647
    std::cout << "\n";//210647

    std::cout << "===== Calculator 3 =====" << "\n";//210647
    calculator3.Show();//210647
    std::cout << "Cost per gram: $" << calculator3.CalculateCostPerGram() << "\n";//210647
    std::cout << "Remaining lifetime: " << calculator3.CalculateRemainingLifetime() << " years\n";//210647
}

