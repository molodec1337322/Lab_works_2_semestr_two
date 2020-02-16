#include <iostream>

using namespace std;

char power(char n, int p = 2)
{
	long result = (long)1;
	for (int j = 0; j < p; j++)
	{
		result *= n;
	}
	return (char)result;
}

long power(long n, int p = 2)
{
	long result = 1;
	for (int j = 0; j < p; j++)
	{
		result *= n;
	}
	return result;
}

int power(int n, int p = 2)
{
	int result = 1;
	for (int j = 0; j < p; j++)
	{
		result *= n;
	}
	return result;
}


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
		cout << "ответ " << answer << endl;

		answer = power((int)number, pow);
		cout << "\nответ " << answer << endl;

		answer = power((long)number, pow);
		cout << "\nответ " << answer << endl;

		answer = power((char)((int)number), pow);
		cout << "\nответ " << answer << endl;
	}
	else
	{
		answer = power(number);
		cout << "ответ " << answer << endl;

		answer = power((int)number);
		cout << "\nответ " << answer << endl;

		answer = power((long)number);
		cout << "\nответ " << answer << endl;

		answer = power((char)number);
		cout << "\nответ " << answer << endl;
	}
	return 0;
}
