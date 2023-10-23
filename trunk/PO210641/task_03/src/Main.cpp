﻿#include "../include./CostCalculator.h"
using namespace std;

int main() {
    CostCalculator calculator1(1, 70.0, 100.0, 5, 1);
    CostCalculator calculator2(2, 50.0, 65.0, 3, 2);
    CostCalculator calculator3(3, 20.0, 40.0, 4, 3);

    cout << "===== Calculator 1 =====" << "\n";
    calculator1.Show();
    cout << "Cost per gram: $" << calculator1.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << calculator1.CalculateRemainingLifetime() << " years\n";
    cout << "\n";

    cout << "===== Calculator 2 =====" << "\n";
    calculator2.Show();
    cout << "Cost per gram: $" << calculator2.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << calculator2.CalculateRemainingLifetime() << " years\n";
    cout << "\n";

    cout << "===== Calculator 3 =====" << "\n";
    calculator3.Show();
    cout << "Cost per gram: $" << calculator3.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << calculator3.CalculateRemainingLifetime() << " years\n";
}

