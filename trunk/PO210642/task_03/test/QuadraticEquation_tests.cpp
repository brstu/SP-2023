#include "QuadraticEquation_tests.h"

TEST(QuadraticEquation1, solveQuadraticEquation) {
    double a1 = 1, b1 = -3, c1 = 2, k1, k2;
    int solutions = solveQuadraticEquation(a1, b1, c1, k1, k2);
    EXPECT_EQ(solutions, 2);
    EXPECT_EQ(k1, 2.0);
    EXPECT_EQ(k2, 1.0);
}
TEST(QuadraticEquation2, solveQuadraticEquation) {
    double a2 = 1, b2 = -2, c2 = 1, n1, n2;
    int solutions = solveQuadraticEquation(a2, b2, c2, n1, n2);
    EXPECT_EQ(solutions, 1);
    EXPECT_EQ(n1, 1.0);
}

TEST(QuadraticEquation3, solveQuadraticEquation) {
    double a3 = 1, b3 = 2, c3 = 3, m1, m2;
    int solutions = solveQuadraticEquation(a3, b3, c3, m1, m2);
    EXPECT_EQ(solutions, 0);
}
