#include <iostream>

using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(): year(0), month(0), day(0)
	{}

	Date(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	void GetDate(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	void ShowDate()
	{
		cout << "Текущая дата: " << month << "/" << day << "/" << year;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int year, month, day;
	char dummyChar;
	Date date;

	cout << "Введите текущую дату mm/dd/yyyy : ";
	cin >> month >> dummyChar >> day >> dummyChar >> year;
	date.GetDate(year, month, day);

	date.ShowDate();
}
