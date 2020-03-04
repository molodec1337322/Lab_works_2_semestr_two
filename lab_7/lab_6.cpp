#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

	void CheckOverflow(int& hours, int& minutes, int& seconds)
	{
		while (seconds >= 60)
		{
			seconds -= 60;
			minutes++;
		}

		while (minutes >= 60)
		{
			minutes -= 60;
			hours++;
		}

		while (seconds < 0)
		{
			seconds += 60;
			minutes--;
		}
		while (minutes < 0)
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
		CheckOverflow(hours, minutes, seconds);
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
		CheckOverflow(hours, minutes, seconds);
		return *this;
	}

	Time operator--(int)
	{
		Time oldVal(hours, minutes, seconds);
		--(*this);
		return oldVal;
	}

	Time operator-(Time t)
	{
		int newSeconds = seconds - t.seconds;
		int newMinutes = minutes - t.minutes;
		int newHours   = hours   - t.hours;

		CheckOverflow(newHours, newMinutes, newSeconds);
		
		return Time(newHours, newMinutes, newSeconds);
	}

	Time operator*(float val)
	{
		int newSeconds = seconds * val;
		int newMinutes = minutes * val;
		int newHours = hours * val;

		CheckOverflow(newHours, newMinutes, newSeconds);

		return Time(newHours, newMinutes, newSeconds);
	}
};


int main()
{
	Time time(2, 0, 50);
	Time time_1 = ++time;
	Time time_2 = time * 3.2;

	cout << "time = ";
	time_1.display();
	cout << "\ntime = ";
	time_2.display();
	cout << endl;
}
