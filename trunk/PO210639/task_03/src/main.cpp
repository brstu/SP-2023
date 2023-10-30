#include "../include/SortAndFindMinMax.h"
#include <iostream>

using namespace std;

void main() {
	int size;
	cout << "Array size: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	sortFromMinToMax(arr, 0, size-1);
	cout << "sort from min to max:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	sortFromMaxToMin(arr, 0, size-1);
	cout << "sort from max to min:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int result = findMinElement(arr, size);
	cout << "min element: " << result << endl;
	result = findMaxElement(arr, size);
	cout << "max element: " << result << endl;
}