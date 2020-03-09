#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class Money
{

private:
	long double money;
	string moneyStr;
	string digits = "0123456789";

	void FormateMoneyStr()
	{
		size_t moneyStrLength = moneyStr.length();
		for (size_t i = moneyStrLength - 1; i > 0; i--)
		{
			if (moneyStrLength - i == 2 && moneyStr[i] != '.')
			{
				moneyStr.insert(i, ".");
			}

			if ((moneyStrLength - i + 1) % 3 == 0 && moneyStrLength - i != 3 && moneyStr[i] != '.')
			{
				moneyStr.insert(i, ".");
			}
		}

		moneyStr.insert(0, "$");
	}

public:

	Money() : money(0)
	{}

	Money(string money) : money(0)
	{
		SetValue(money);
	}

	Money(double money) : money(money)
	{
		moneyStr = to_string(money);
		FormateMoneyStr();
	}

	void SetValue(string val)
	{
		string numbers;
		for (auto c : val)
		{
			if (digits.find(c) != string::npos)
			{
				numbers += c;
			}
		}
		moneyStr = numbers;
		FormateMoneyStr();

		char* numbersCh = new char[numbers.length() + 1];
		strncpy(numbersCh, numbers.c_str(), numbers.length());
		money = atof(numbersCh);
		money /= 100;
	}

	double GetValueD() const
	{
		return money;
	}

	string GetValueS()
	{
		return moneyStr;
	}

	Money operator+(Money m)
	{
		double newMoney = money + m.money;
		string newMoneyStr = to_string(newMoney);

		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}

	Money operator-(Money m)
	{
		double newMoney = money - m.money;
		string newMoneyStr = to_string(newMoney);

		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}

	Money operator/(Money m)
	{
		double newMoney = money / m.money;
		string newMoneyStr = to_string(newMoney);

		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}

	Money operator*(long double d)
	{
		double newMoney = money * d;
		string newMoneyStr = to_string(newMoney);

		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}

	Money operator/(long double d)
	{
		double newMoney = money / d;
		string newMoneyStr = to_string(newMoney);

		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}
};


class Sterling
{
private:
	long pounds;
	int shillings;
	int penny;

	double decimalPounds;

	void ConvertFromDecimalToOldPounds()
	{
		double pennyTemp, temp1, temp2;

		penny = decimalPounds * 240;
		pounds = static_cast<long>(decimalPounds);
		pennyTemp = pounds * 240;
		temp1 = penny - pennyTemp;
		temp1 = static_cast<int>(temp1);
		shillings = temp1 / 12;
		shillings = static_cast<int>(shillings);
		temp2 = shillings * 12;
		penny = temp1 - temp2;
	}

	void ConvertFromOldToDecimalPounds()
	{
		decimalPounds = pounds + (penny / 12 + shillings) / 20;
	}

public:
	Sterling() : pounds(0), shillings(0), penny(0), decimalPounds(0.0)
	{}

	Sterling(double decimalPounds) :pounds(0), shillings(0), penny(0), decimalPounds(decimalPounds)
	{
		ConvertFromDecimalToOldPounds();
	}

	Sterling(long pounds, int shillings, int penny) : pounds(pounds), shillings(shillings), penny(penny), decimalPounds(0.0)
	{
		ConvertFromOldToDecimalPounds();
	}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "\n";
	}

	double GetDecimalPounds() const
	{
		return decimalPounds;
	}

	Sterling operator+(Sterling s)
	{
		double newDecimalPounds = decimalPounds + s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator-(Sterling s)
	{
		double newDecimalPounds = decimalPounds - s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(Sterling s)
	{
		double newDecimalPounds = decimalPounds / s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator*(double d)
	{
		double newDecimalPounds = decimalPounds * d;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(double d)
	{
		double newDecimalPounds = decimalPounds / d;
		return Sterling(newDecimalPounds);
	}
};


Money SterlingToMoney(Sterling s)
{
	return Money(s.GetDecimalPounds() * 50);
}

Sterling MoneyToSterling(Money m)
{
	return Sterling(m.GetValueD() / 50);
}


int main()
{
	setlocale(LC_ALL, "Russian");

	string userResponce;

	long pounds;
	int shillings, penny;
	char ch;

	cout << "Введите сумму в долларах: ";
	cin >> userResponce;
	Money dollars_1(userResponce);
	
	cout << "Введите сумму в старых фунтах: ";
	cin >> pounds >> ch >> shillings >> ch >> penny;
	Sterling sterling_1(pounds, shillings, penny);

	Money dollars_2 = SterlingToMoney(sterling_1);

	Money dollars_3 = dollars_1 + dollars_2;

	cout << "Итого получилось: " << dollars_3.GetValueS();
}
