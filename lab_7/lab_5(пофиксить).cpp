#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

	void CheckOverflow()
	{
		if (seconds >= 60)
		{
			seconds -= 60;
			minutes++;
		}
		if (minutes >= 60)
		{
			minutes -= 60;
			hours++;
		}

		if (seconds < 0)
		{
			seconds += 60;
			minutes--;
		}
		if (minutes < 0)
		{
			minutes += 60;
			hours--;
		}
	}

public:

	Time() : hours(0), minutes(0), seconds(0)
	{}

	Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds)
	{}

	void display() const
	{
		cout << hours << ":" << minutes << ":" << seconds;
	}

	Time& operator++()
	{
		++seconds;
		CheckOverflow();
		return *this;
	}

	Time operator++(int)
	{
		Time oldVal(hours, minutes, seconds);
		++(*this);
		return oldVal;
	}

	Time& operator--()
	{
		--seconds;
		CheckOverflow();
		return *this;
	}

	Time operator--(int)
	{
		Time oldVal(hours, minutes, seconds);
		--(*this);
		return oldVal;
	}
};


int main()
{
	const Time time(2, 0, 50);
	

	cout << "time = ";
	time.display();
	cout << "\ntime = ";
	++time.display();
	cout << endl;
}
