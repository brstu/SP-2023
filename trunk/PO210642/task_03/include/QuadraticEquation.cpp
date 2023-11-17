#include "QuadraticEquation.h"
#include <cmath>
#include <complex>

int solveQuadraticEquation(double a, double b, double c, std::complex<double>& x1, std::complex<double>& x2)
{
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return 2; 
    }
    else if (discriminant == 0)
    {
        x1 = -b / (2 * a);
        x2 = x1;  
        return 1;
    }
    else
    {
        x1 = (-b + std::sqrt(std::complex<double>(discriminant))) / (2 * a);
        x2 = (-b - std::sqrt(std::complex<double>(discriminant))) / (2 * a);
        return 0;
    }
}
