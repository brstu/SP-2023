#include "QuadraticEquation_tests.h"

TEST(QuadraticEquation1, solveQuadraticEquation) {
    double a1 = 1;
    double b1 = -3;
    double c1 = 2;
    std::complex<double> k1, k2;
    int solutions = solveQuadraticEquation(a1, b1, c1, k1, k2);
    EXPECT_EQ(solutions, 2);
    EXPECT_TRUE(k1 == std::complex<double>(2.0, 0.0));
    EXPECT_TRUE(k2 == std::complex<double>(1.0, 0.0));
}

TEST(QuadraticEquation2, solveQuadraticEquation) {
    double a2 = 1;
    double b2 = -2;
    double c2 = 1;
    std::complex<double> n1, n2;
    int solutions = solveQuadraticEquation(a2, b2, c2, n1, n2);
    EXPECT_EQ(solutions, 1);
    EXPECT_TRUE(n1 == std::complex<double>(1.0, 0.0));
    EXPECT_TRUE(n2 == std::complex<double>(1.0, 0.0));
}

TEST(QuadraticEquation3, solveQuadraticEquation) {
    double a3 = 1;
    double b3 = 2;
    double c3 = 3;
    std::complex<double> m1, m2;
    int solutions = solveQuadraticEquation(a3, b3, c3, m1, m2);
    EXPECT_EQ(solutions, 0);
    EXPECT_TRUE(std::imag(m1) != 0.0 || std::imag(m2) != 0.0);
}

TEST(QuadraticEquation4, solveQuadraticEquation) {
    double a4 = 1;
    double b4 = 1;
    double c4 = 1;
    std::complex<double> p1, p2;
    int solutions = solveQuadraticEquation(a4, b4, c4, p1, p2);
    EXPECT_EQ(solutions, 0);
    EXPECT_TRUE(std::imag(p1) != 0.0 || std::imag(p2) != 0.0);
}

TEST(QuadraticEquation5, solveQuadraticEquation) {
    double a5 = 1;
    double b5 = 0;
    double c5 = 1;
    std::complex<double> q1, q2;
    int solutions = solveQuadraticEquation(a5, b5, c5, q1, q2);
    EXPECT_EQ(solutions, 0);
    EXPECT_TRUE(std::imag(q1) != 0.0 || std::imag(q2) != 0.0);
}

