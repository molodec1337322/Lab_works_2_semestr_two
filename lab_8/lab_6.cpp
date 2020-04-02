#include <iostream>

using namespace std;

class safearay
{
private:
	static const int LIMIT = 100;
	int arr[LIMIT];

public:
	int& operator [](int n) //note: return by reference
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return arr[n];
	}
};


class AdvancedSafeArray : safearay
{
private:
	int lowerBorder;
	int upperBorder;

public:
	AdvancedSafeArray() : lowerBorder(0), upperBorder(0)
	{}

	AdvancedSafeArray(int lowerBorder, int upperBorder) : lowerBorder(lowerBorder), upperBorder(upperBorder)
	{}

	void SetBorders(int lowerBorder, int upperBorder)
	{
		this->lowerBorder = lowerBorder;
		this->upperBorder = upperBorder;
	}

	int& operator[](int n)
	{
		if (n < lowerBorder || n > upperBorder)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		safearay::operator[](n);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	AdvancedSafeArray arr(10, 20);
	arr[17] = 5;
	cout << arr[17];
	arr[28] = 10;
	cout << arr[28];
}
