#include <iostream>

using namespace std;


template<typename T>
class LinkedArrays
{
private:
	T** ap;
	int size_x;
	int size_y;

public:
	LinkedArrays(int size_x, int size_y) : size_x(size_x), size_y(size_y)
	{
		ap = new T* [size_x];
		for (int i = 0; i < size_x; i++)
		{
			*(ap + i) = new T[size_y];
		}
	}

	int& operator[](int index)
	{
		if (index > size_x * size_y)
		{
			cout << "Out of range";
			exit(1);
		}

		return ap[index / size_x][index % size_y];
	}
};


int main()
{
	LinkedArrays<int> arr(5, 5);

	for (int i = 0; i < 25; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 25; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
