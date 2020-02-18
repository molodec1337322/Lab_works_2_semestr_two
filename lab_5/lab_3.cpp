#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes; 
	int seconds;

public:

	Time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int hours, int minutes, int seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	void add_time(Time time_1, Time time_2)
	{
		seconds = time_1.seconds + time_2.seconds; 

		if (seconds > 59)
		{
			seconds -= 60; minutes++;
		} 

		minutes += time_1.minutes + time_2.minutes; 

		if (minutes > 59) 
		{
			minutes -= 60; hours++;
		} 

		hours += time_1.hours + time_2.hours; 
	}

	void display() const
	{
		cout << hours << ":" << minutes << ":" << seconds;
	}
};

int main()
{
	const Time time1(2, 0, 50);
	const Time time2(4, 20, 0); 
	Time time3;

	time3.add_time(time1, time2);

	cout << "time 3 = "; 
	time3.display();
	cout << endl;
}
