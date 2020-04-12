#include <iostream>

using namespace std;


class Array 
{
private:
	int* ptr; 
	int size; 

public:
	Array(int s) 
	{
		size = s; 
		ptr = new int[s]; 
	}

	~Array() 
	{
		delete[] ptr;
	}

	int& operator [] (int j) 
	{
		return *(ptr + j);
	}

	Array& operator=(const Array& arr)
	{
		delete[] ptr;
		ptr = new int[arr.size];
		size = arr.size;
		for (int i = 0; i < arr.size; i++)
		{
			*(ptr + i) = *(arr.ptr + i);
		}

		return *this;
	}
};


int main()
{
	const int ASIZE = 10; 
	Array arr(ASIZE); 
	Array arrCopy(0);

	for (int j = 0; j < ASIZE; j++) 
		arr[j] = j * j;

	arrCopy = arr;

	for (int j = 0; j < ASIZE; j++) 
		cout << arrCopy[j] << ' ';

	cout << endl;
	return 0;
}
