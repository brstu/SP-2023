#include "CostCalculator_tests.h"

TEST(CostCalculator, CalculateCostPerGram) {//1
	CostCalculator obj;//1
	EXPECT_EQ(5, obj.CalculateCostPerGram());//1
}

TEST(CostCalculator, CalculateRemainingLifetime) {//1
	CostCalculator obj1;//1
	EXPECT_EQ(2, obj1.CalculateRemainingLifetime());//1
}