#include <iostream>

using namespace std;

class Angle
{
private:
	int degrees;
	float minutes;
	char direction;

public:
	Angle() : degrees(0), minutes(0.0), direction(' ')
	{}

	Angle(int degrees, float minutes, char direction)
	{
		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}

	void SetAngle(int degrees, float minutes, char direction)
	{
		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}

	void ShowAngle()
	{
		cout << degrees << "°" << minutes << "'" << direction;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Angle angle(120, 56.8, 'N');
	cout << "angle 1 is: "; angle.ShowAngle();

	int degrees;
	float minutes;
	char direction;

	char userResponce;
	const char EXITKEY = 27;

	while (true)
	{
		cout << "\nВведите новые координаты по типу ddd mm D : ";
		cin >> degrees >> minutes >> direction;
		angle.SetAngle(degrees, minutes, direction);
		angle.ShowAngle();
	}
}
