#include <iostream>

using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	
	Date date;
	int month, day, year;
	char dummyChar;

	cout << "Введите день своего рождения в формате мм/дд/гггг: ";
	cin >> month >> dummyChar >> day >> dummyChar >> year;

	if (month > 12 || month < 1 || day > 31 || day < 1)
	{
		cout << "Введенная дата не является корректной";
	}
	else
	{
		date.month = month;
		date.day = day;
		date.year = year;

		cout << date.month << "/" << date.day << "/" << date.year;
	}
}