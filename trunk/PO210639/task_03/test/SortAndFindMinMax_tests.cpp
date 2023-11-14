#include "SortAndFindMinMax_tests.h"

TEST(SortAndFindMinMax,findMaxElement) {
	std::vector<int> arr1 = { 4, 6, 2, 7, 3 };
	EXPECT_EQ(7, findMaxElement(arr1, 5));
}

TEST(SortAndFindMinMax, findMinElement) {
	std::vector<int> arr2 = { 4, 6, 2, 7, 3 };
	EXPECT_EQ(2, findMinElement(arr2, 5));
}

TEST(SortAndFindMinMax, sortFromMinToMax) {
	std::vector<int> arr3 = { 4, 6, 2, 7, 3 };
	std::vector<int> sortFromMinToMaxArr = { 2, 3, 4, 6, 7 };
	sortFromMinToMax(arr3, 0, 4);
	EXPECT_EQ(arr3, sortFromMinToMaxArr);
}

TEST(SortAndFindMinMax, sortFromMaxToMin) {
	std::vector<int> arr4 = { 4, 6, 2, 7, 3 };
	std::vector<int> sortFromMaxToMinArr = { 7, 6, 4, 3, 2};
	sortFromMaxToMin(arr4, 0, 4);
	EXPECT_EQ(arr4, sortFromMaxToMinArr);
}
