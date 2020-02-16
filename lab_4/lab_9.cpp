#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

void swap(Time& firstTime, Time& secondTime) {
	Time temp = firstTime;
	firstTime = secondTime;
	secondTime = temp;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Time firstTime, secondTime;
	char dummyChar;

	cout << "Введите первое значение времени hh:mm:ss : ";
	cin >> firstTime.hours >> dummyChar >> firstTime.minutes >> dummyChar >> firstTime.seconds;
	cout << "Введите второе значение времени hh:mm:ss : ";
	cin >> secondTime.hours >> dummyChar >> secondTime.minutes >> dummyChar >> secondTime.seconds;

	swap(firstTime, secondTime);
	cout << firstTime.hours << " " << firstTime.minutes << " " << firstTime.seconds << endl;
}
