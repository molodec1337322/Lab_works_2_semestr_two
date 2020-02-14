#include <iostream>

using namespace std;

float circarea(float r)
{
	const float PI = 3.14159F;
	return r * r * PI;
}

int main()
{
	double rad;
	cout << "ведите радиус окружности:";
	cin >> rad;
	cout << "площадь равна " << circarea(rad) << endl;
}