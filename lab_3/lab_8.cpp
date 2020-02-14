#include <iostream>

using namespace std;

struct Fraction
{
	int a;
	int b;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Fraction fr_1, fr_2;
	char dummyChar;
	cout << "Введите дробь 1: ";
	cin >> fr_1.a >> dummyChar >> fr_1.b;
	cout << "Введите дробь 2: ";
	cin >> fr_2.a >> dummyChar >> fr_2.b;

	Fraction fr_3;
	fr_3.a = fr_1.a * fr_2.b + fr_2.a * fr_1.b;
	fr_3.b = fr_1.b * fr_2.b;
	cout << "Дробь 3 равна: " << fr_3.a << "/" << fr_3.b;
}
