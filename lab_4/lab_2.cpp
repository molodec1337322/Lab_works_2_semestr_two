#include <iostream>

using namespace std;

double power(double n, int p = 2)
{
	double result = 1.0;
	for (int j = 0; j < p; j++)
	{
		result *= n;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double number, answer;
	int pow;
	char userResponse;
	cout << "\nведите число:";
	cin >> number;
	cout << "Будете вводить степень (y/n)?";
	cin >> userResponse;
	if (userResponse == 'y ')
	{
		cout << "Введите степень:";
		cin >> pow;
		answer = power(number, pow);
	}
	else
	{
		answer = power(number);
	}
	cout << "ќтвет " << answer << endl;
	return 0;
}
