#include "SortAndFindMinMax.h"
#include <iostream>

using namespace std;

void sortFromMinToMax(int* Arr, int first, int last)
{
	int i = first, j = last, x = Arr[(first + last) / 2];
	do {
		while (Arr[i] < x) i++;
		while (Arr[j] > x) j--;
		if (i <= j) {
			if (Arr[i] > Arr[j]) swap(Arr[i], Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) sortFromMinToMax(Arr, i, last);
	if (first < j) sortFromMinToMax(Arr, first, j);
}

void sortFromMaxToMin(int* Arr, int first, int last)
{
	int i = first, j = last, x = Arr[(first + last) / 2];
	do {
		while (Arr[i] > x) i++;
		while (Arr[j] < x) j--;
		if (i <= j) {
			if (Arr[i] < Arr[j]) swap(Arr[i], Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) sortFromMaxToMin(Arr, i, last);
	if (first < j) sortFromMaxToMin(Arr, first, j);
}

int findMinElement(int* arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement > arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}


int findMaxElement(int* arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement < arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}