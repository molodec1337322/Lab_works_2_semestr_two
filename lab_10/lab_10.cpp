//меня воротит от здешних костылей, но оно работает по крайней мере
#include <iostream>

using namespace std;


class LinkedArrays
{
private:
	int** ap;
	const static int size = 3;
	const static int subSize = 3;

public:
	LinkedArrays()
	{
		ap = new int* [size];
		for (int i = 0; i < size; i++)
		{
			int* subArr = new int[subSize];
			*(ap + i) = subArr;
		}
	}

	~LinkedArrays()
	{}

	LinkedArrays& operator=(const LinkedArrays& right)
	{
		delete ap;
		ap = new int* [size];
		for (int i = 0; i < size; i++)
		{
			*(ap + i) = right.ap[i];
		}

		return *this;
	}

	int& operator()(int j, int k)
	{
		return *(*(ap + j) + k);
	}
};


int main()
{
	LinkedArrays* arr = new LinkedArrays;
	arr->operator()(0, 0) = 0;
	arr->operator()(0, 1) = 1;
	arr->operator()(1, 1) = 10;

	cout << arr->operator()(0, 0) << endl << arr->operator()(0, 1) << endl << arr->operator()(1, 1) << "\n\n";

	LinkedArrays* arr_2 = new LinkedArrays;
	arr_2->operator=(*arr);
	delete arr;

	cout << arr_2->operator()(0, 0) << endl << arr_2->operator()(0, 1) << endl << arr_2->operator()(1, 1);

	return 0;
}
