#include "CostCalculator_tests.h"

TEST(CostCalculator, CalculateCostPerGram) {//210647
	CostCalculator obj;//210647
	EXPECT_EQ(5, obj.CalculateCostPerGram());//210647
}

TEST(CostCalculator, CalculateRemainingLifetime) {//210647
	CostCalculator obj1;//210647
	EXPECT_EQ(2, obj1.CalculateRemainingLifetime());//210647
}