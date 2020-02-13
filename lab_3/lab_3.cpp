#include <iostream>

using namespace std;

struct Distance
{
	int feet;
	float inches;
};

struct Volume

{
	Distance length;
	Distance width;
	Distance height;
};


int main()
{
	setlocale(LC_ALL, "Russian");

	float length, width, height;
	Volume room1 = { { 16, 3.5 }, { 12, 6.25 }, { 8, 1.75 } };
	length = room1.length.feet + room1.length.inches / 12.0;
	width = room1.width.feet + room1.width.inches / 12.0;
	height = room1.height.feet + room1.height.inches / 12.0;
	cout << "Объем равен = " << length * width * height << " кубичесих футов\n";
}