#include <iostream>

using namespace std;

struct Time
{
	int seconds;
	int minutes;
	int hours;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Time time;
	char dummyChar;
	cout << "Введите время в формате hh/mm/ss: ";
	cin >> time.hours >> dummyChar >> time.minutes >> dummyChar >> time.seconds;

	long totalsecs = time.hours * 3600 + time.minutes * 60 + time.seconds;
	cout << "Секунд в веденном времени: " << totalsecs;
}
