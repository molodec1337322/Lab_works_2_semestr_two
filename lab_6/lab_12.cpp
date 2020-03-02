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

	Money operator + (Money m)
	{
		double newMoney = money + m.money;
		int max_1 = to_string(round(money)).length();
		int max_2 = to_string(round(m.money)).length();
		int max = max_1 > max_2 ? max_1 : max_2;

		string mStr = to_string(newMoney);
		for (size_t i = mStr.length(); i > 0 && i <= max; i--)
		{
			if (mStr[i] == '0')
			{
				mStr.erase(i);
			}
		}

		while (mStr.length() - max <= 2)
		{
			mStr.append("0");
		}

		return Money(mStr);
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	string userResponce;
	Money dollars_1, dollars_2, dollars_3;
	cout << "Введите сумму в долларах: ";
	cin >> userResponce;
	dollars_1.SetValue(userResponce);
	cout << "Введите другую сумму в долларах: ";
	cin >> userResponce;
	dollars_2.SetValue(userResponce);

	dollars_3 = dollars_1 + dollars_2;

	cout << "Итого получилось" << dollars_3.GetValueS();
}
