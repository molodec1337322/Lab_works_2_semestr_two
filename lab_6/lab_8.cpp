#include <iostream>

using namespace std;

class SafeArray
{
private:
	const static int LIMIT_MAX = 500;
	const static int LIMIT_MIN = 0;
	int arr[LIMIT_MAX];

public:
	SafeArray()
	{}

	void PutEl(int pos, int el)
	{
		if (pos > LIMIT_MIN || pos < LIMIT_MAX)
		{
			arr[pos] = el;
		}
	}

	int GetEl(int pos)
	{
		if (pos > LIMIT_MIN || pos < LIMIT_MAX)
		{
			return arr[pos];
		}
		return 0;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	SafeArray arr;
	int temp = 123;
	arr.PutEl(7, 123);
	cout << arr.GetEl(7);
}
