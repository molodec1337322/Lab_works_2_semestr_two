#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

long time_to_secs(Time time) {
	return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

Time secs_to_time(long secs) {
	Time first;
	first.hours = secs / 3600;
	secs %= 3600;
	first.minutes = secs / 60;
	first.seconds = secs % 60;
	return first;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Time firstTime, secondTime;
	char dummyChar;

	cout << "Введите первое значение времени hh:mm:ss : ";
	cin >> firstTime.hours >> dummyChar >> firstTime.minutes >> dummyChar >> firstTime.seconds;
	cout << "Введите второе значение времени hh:mm:ss : ";
	cin >> secondTime.hours >> dummyChar >> secondTime.minutes >> dummyChar >> secondTime.seconds;

	Time result = secs_to_time(time_to_secs(firstTime) + time_to_secs(secondTime));

	cout << "Результат : " << result.hours << ":" << result.minutes << ":" << result.seconds << endl;
}
