#include "SortAndFindMinMax_tests.h"

TEST(SortAndFindMinMax,findMaxElement) {
	int arr1[5] = { 4, 6, 2, 7, 3 };
	EXPECT_EQ(7, findMaxElement(arr1, 5));
}

TEST(SortAndFindMinMax, findMinElement) {
	int arr2[5] = { 4, 6, 2, 7, 3 };
	EXPECT_EQ(2, findMinElement(arr2, 5));
}

TEST(SortAndFindMinMax, sortFromMinToMax) {
	int arr3[5] = { 4, 6, 2, 7, 3 };
	int sortFromMinToMaxArr[5] = { 2, 3, 4, 6, 7 };
	sortFromMinToMax(arr3, 0, 4);
	EXPECT_TRUE(0 == std::memcmp(arr3, sortFromMinToMaxArr, sizeof(arr3)));
}

TEST(SortAndFindMinMax, sortFromMaxToMin) {
	int arr4[5] = { 4, 6, 2, 7, 3 };
	int sortFromMaxToMinArr[5] = { 7, 6, 4, 3, 2};
	sortFromMaxToMin(arr4, 0, 4);
	EXPECT_TRUE(0 == std::memcmp(arr4, sortFromMaxToMinArr, sizeof(arr4)));
}
