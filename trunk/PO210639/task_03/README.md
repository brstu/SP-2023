# Лабораторная работа №3 #

## DLL: динамически загружаемые библиотеки ##

## Вариант 2 ##

### Цель работы: Научиться создавать простейшие DLL ###

#### **Условие** ####

Создать библиотеку, сортирующую массив по убыванию и возрастанию, а также находящую максимум/минимум в массиве.

Сортировка по убыванию:

```c++
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
```

Сортировка по возрастанию:

```c++
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
```

Поиск минимального элемента:

```c++
int findMinElement(int* arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement > arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}
```

Поиск максимального элемента:

```c++
int findMaxElement(int* arr, int size) {
	int resultElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (resultElement < arr[i]) {
			resultElement = arr[i];
		}
	}
	return resultElement;
}
```

Основная программа:

```c++
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
```

#### Результат ####

![img.png](images/img.png)

#### Вывод ####

Научились создавать простейшие DLL.
