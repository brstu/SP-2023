#include <iostream>
#include "item.h"
using namespace std;

int main() {
    Item item1(1, 70.0, 100.0, 5, 1);
    Item item2(2, 50.0, 65.0, 3, 2);
    Item item3(3, 20.0, 40.0, 4, 3);

    cout << "===== Item1 =====" << "\n";
    item1.Show();
    cout << "Cost per gram: $" << item1.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << item1.CalculateRemainingLifetime() << " years\n";
    cout << "\n";

    cout << "===== Item 2 =====" << "\n";
    item2.Show();
    cout << "Cost per gram: $" << item2.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << item2.CalculateRemainingLifetime() << " years\n";
    cout << "\n";

    cout << "===== Item 3 =====" << "\n";
    item3.Show();
    cout << "Cost per gram: $" << item3.CalculateCostPerGram() << "\n";
    cout << "Remaining lifetime: " << item3.CalculateRemainingLifetime() << " years\n";
}

