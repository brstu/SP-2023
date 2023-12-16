#include "SortAndFindMinMax.h"
#include <iostream>
#include <numeric>

void sortFromMinToMax(std::vector<int> &Arr, int first, int last)
{
	int i = first;
	int j = last;
	int x = Arr[std::midpoint(first,last)];
	do {
		while (Arr[i] < x) i++;
		while (Arr[j] > x) j--;
		if (i <= j) {
			if (Arr[i] > Arr[j]) std::swap(Arr[i], Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) sortFromMinToMax(Arr, i, last);
	if (first < j) sortFromMinToMax(Arr, first, j);
}

void sortFromMaxToMin(std::vector<int> &Arr, int first, int last)
{
	int i = first;
	int j = last;
	int x = Arr[std::midpoint(first, last)];
	do {
		while (Arr[i] > x) i++;
		while (Arr[j] < x) j--;
		if (i <= j) {
			if (Arr[i] < Arr[j]) std::swap(Arr[i], Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) sortFromMaxToMin(Arr, i, last);
	if (first < j) sortFromMaxToMin(Arr, first, j);
}

int findMinElement(std::vector<int> &arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement > arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}


int findMaxElement(std::vector<int> &arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement < arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}