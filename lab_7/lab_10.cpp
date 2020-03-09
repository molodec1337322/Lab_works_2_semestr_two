#include <iostream>
#include "math.h"

using namespace std;

class Polar
{
private:
	int x;
	int y;

	double radius;
	double angle;

public:
	Polar(): x(0), y(0), angle(0), radius(x* x + y * y)
	{}

	Polar(int x, int y): x(x), y(y), radius(sqrt(x* x + y * y)), angle(acos((double)x / (double)radius))
	{}

	Polar operator + (Polar p)
	{
		int newX = x + p.x;
		int newY = y + p.y;

		return Polar(newX, newY);
	}

	double GetRadius() const
	{
		return radius;
	}

	double GetAngle() const
	{
		return angle;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Polar p1(0, 5), p2(5, 0);
	Polar p3 = p1 + p2;
	cout << "Полярный радиус новой координаты: " << p3.GetRadius() << "\nПолярный угол равен: " << p3.GetAngle();
}
