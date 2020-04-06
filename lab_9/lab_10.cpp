#include <iostream>

using namespace std;


class LinkedArrays
{
private:
	int** ap;
	int size;
	const static int subSize = 3;

public:
	LinkedArrays(int size) : size(size)
	{
		ap = new int*[size];
		for (int i = 0; i < size; i++)
		{
			*(ap + i) = new int[subSize];
		}
	}

	int& operator()(int j, int k)
	{
		return *(*(ap + j) + k);
	}
};


int main()
{
	LinkedArrays arr(2);
	arr(0, 0) = 0;
	arr(0, 1) = 1;
	arr(1, 1) = 10;

	cout << arr(0, 0) << endl << arr(0, 1) << endl << arr(1, 1);
	return 0;
}
