#include <iostream>

using namespace std;

int maxIndex(int arr[], int size)
{
	int maxint = 0;
	int maxnum = arr[maxint];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > maxnum)
		{
			maxint = i;
			maxnum = arr[i];
		}
	}

	return maxint;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int size = 10;
	int arr[size];
	cout << "Введите числа массива: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "Наибольшее число находится под номером" << maxIndex(arr, size);
}
