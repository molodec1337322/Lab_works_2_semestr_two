#include <iostream>

using namespace std;

class SafeArray
{
private:
	const static int LIMIT_MAX = 500;
	const static int LIMIT_MIN = 0;

	int userMin;
	int userMax;

	int arr[LIMIT_MAX];

public:
	SafeArray() : userMin(LIMIT_MIN), userMax(LIMIT_MAX)
	{}

	SafeArray(int min, int max): userMin(min), userMax(max)
	{}

	void PutEl(int pos, int el)
	{
		if (pos > userMin && pos < userMax)
		{
			arr[pos] = el;
		}
		else
		{
			cout << "\nЗа пределами массива\n";
		}
	}

	int GetEl(int pos)
	{
		if (pos > userMin && pos < userMax)
		{
			return arr[pos];
		}
		else
		{
			cout << "\nЗа пределами массива\n";
			return 0;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	SafeArray arr(100, 200);
	int temp = 123;
	arr.PutEl(7, 123);
	cout << arr.GetEl(7);
}
