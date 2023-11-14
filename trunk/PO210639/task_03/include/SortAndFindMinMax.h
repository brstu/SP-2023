#pragma once
#include <vector>
#ifndef HEADERH
#define HEADERH

void sortFromMinToMax(std::vector<int> &Arr, int first, int last);

void sortFromMaxToMin(std::vector<int> &Arr, int first, int last);

int findMinElement(std::vector<int> &arr, int size);

int findMaxElement(std::vector<int> &arr, int size);

#endif