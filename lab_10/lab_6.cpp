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
	string numbersStr;
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
		numbersStr = moneyStr = numbers;
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

	friend Money operator * (long double, Money);
	friend Money operator / (long double, Money);
};

Money operator*(long double number, Money m) 
{
	long double newMoney = number * m.money;
	string newMoneyStr = to_string(newMoney);
	return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
}
Money operator/(long double number, Money m) 
{
	long double newMoney = number / m.money;
	string newMoneyStr = to_string(newMoney);
	return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
}

int main() // $124
{
	Money money("123.123.50$");
	long double num = 123123.50;
	Money result = num / money;
	cout << result.GetValueS();
}
