#include "CostCalculator_tests.h"

TEST(CostCalculator, CalculateCostPerGram) {
	CostCalculator obj;
	EXPECT_EQ(10, obj.CalculateCostPerGram());
}

TEST(CostCalculator, CalculateRemainingLifetime) {
	CostCalculator obj1;
	EXPECT_EQ(10, obj1.CalculateRemainingLifetime());
}