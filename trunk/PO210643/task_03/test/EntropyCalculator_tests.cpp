#include "EntropyCalculator_tests.h"

TEST(EntropyCalculator, calculateEntropy) {
	EntropyCalculator obj;
	EXPECT_EQ(1.9182958340544893, obj.calculateEntropy("people"));
}

