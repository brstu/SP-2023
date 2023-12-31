﻿#include <iostream>
#include <complex>
#include "../include/QuadraticEquation.h"
#include "../include/QuadraticEquation.cpp"

int main()
{
    double a;
    double b;
    double c;
    std::complex<double> x1;
    std::complex<double> x2;

    std::cout << "Enter the coefficients a, b, and c: ";
    std::cin >> a >> b >> c;

    if (int solutions = solveQuadraticEquation(a, b, c, x1, x2); solutions == 0)
    {
        std::cout << "Complex roots: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }
    else if (solutions == 1)
    {
        std::cout << "One root: x = " << x1 << std::endl;
    }
    else
    {
        std::cout << "Two roots: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }

    return 0;
}
