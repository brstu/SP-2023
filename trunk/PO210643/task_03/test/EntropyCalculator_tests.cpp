#include "EntropyCalculator_tests.h"

TEST(CostCalculator, CalculateCostPerGram) {
	CostCalculator obj;
	EXPECT_EQ(5, obj.CalculateCostPerGram());
}

TEST(CostCalculator, CalculateRemainingLifetime) {
	CostCalculator obj1;
	EXPECT_EQ(2, obj1.CalculateRemainingLifetime());
}