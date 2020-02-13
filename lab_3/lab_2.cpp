#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Point p1, p2, p3;

	cout << "Введите координаты первой точки: ";
	cin >> p1.x >> p1.y;
	cout << "Введите координаты второй точки: ";
	cin >> p2.x >> p2.y;

	cout << "Координаты третьей точки равны: " << p1.x + p2.x << " " << p1.y + p2.y;
}