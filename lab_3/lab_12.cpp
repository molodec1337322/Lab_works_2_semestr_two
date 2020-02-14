#include <iostream>

using namespace std;

struct Fraction
{
	int a;
	int b;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Fraction fr_1, fr_2;
	int firstNumHalves[2];
	int secondNumHalves[2];
	int upperHalf, bottomHalf;
	char userResponceToContinue;
	char userResponceOperation;

	string firstNum, secondNum;

	do {
		cout << "Введите первую дробь: ";
		cin >> firstNum;
		cout << "Введите вторую дробь: ";
		cin >> secondNum;
		cout << "Введите действие: ";
		cin >> userResponceOperation;

		size_t slashPos;
		for (size_t i = 0; i < firstNum.size(); i++)
		{
			if (firstNum[i] == '/')
			{
				slashPos = i;
				break;
			}
		}

		fr_1.a = atoi(firstNum.substr(0, slashPos).c_str());
		fr_1.b = atoi(firstNum.substr(slashPos + 1, firstNum.size()).c_str());

		for (size_t i = 0; i < secondNum.size(); i++)
		{
			if (secondNum[i] == '/')
			{
				slashPos = i;
				break;
			}
		}

		fr_2.a = atoi(secondNum.substr(0, slashPos).c_str());
		fr_2.b = atoi(secondNum.substr(slashPos + 1, secondNum.size()).c_str());

		switch (userResponceOperation)
		{
		case '+':
			upperHalf = fr_1.a * fr_2.b + fr_2.a * fr_1.b;
			bottomHalf = fr_1.b * fr_2.b;
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '-':
			upperHalf = fr_1.a * fr_2.b - fr_2.a * fr_1.b;
			bottomHalf = fr_1.b * fr_2.b;
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '*':
			upperHalf = fr_1.a * fr_2.a;
			bottomHalf = fr_1.b * fr_2.b;
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '/':
			upperHalf = fr_1.a * fr_2.b;
			bottomHalf = fr_1.b * fr_2.a;
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		default:
			cout << "Такого действия не существует\n";
			break;
		}

		cout << "\nХотите продолжить? (y/n): ";
		cin >> userResponceToContinue;

	} while (userResponceToContinue == 'y');
}
