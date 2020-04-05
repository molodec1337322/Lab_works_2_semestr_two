#include <iostream>

using namespace std;

template<typename T>
void Addarrays(const T* arr1, const T* arr2, T* arr3, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}
}

template<typename T>
void DispalyArray(const T* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int SIZE = 3;
	int* arr1 = new int[SIZE];
	int* arr2 = new int[SIZE];
	int* arr3 = new int[SIZE];
	arr1[0] = 1; arr1[1] = 3; arr1[2] = 5;
	arr2[0] = 5; arr2[1] = 3; arr2[2] = 1;

	Addarrays(arr1, arr2, arr3, SIZE);
	DispalyArray(arr3, SIZE);

	return 0;
}
