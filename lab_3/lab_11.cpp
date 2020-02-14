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
	
	Time time_1, time_2;
	char dummyChar;
	cout << "Введите время 1 в формате чч:мм:сс : ";
	cin >> time_1.hours >> dummyChar >> time_1.minutes >> dummyChar >> time_1.seconds;
	cout << "Введите время 2 в формате чч:мм:сс : ";
	cin >> time_2.hours >> dummyChar >> time_2.minutes >> dummyChar >> time_2.seconds;

	long totalSeconds = time_1.hours * 3600 + time_2.hours * 3600 + time_1.minutes * 60 + time_2.minutes * 60 + time_1.seconds + time_2.seconds;

	Time timeTotal;
	timeTotal.hours = totalSeconds / 3600;
	totalSeconds %= 3600;
	timeTotal.minutes = totalSeconds / 60;
	totalSeconds %= 60;
	timeTotal.seconds = totalSeconds;

	cout << "Сумма времени равна: " << timeTotal.hours << ":" << timeTotal.minutes << ":" << timeTotal.seconds;
}
