#include <iostream>

using namespace std;

class Distance //класс английских расстояний
{
private:
	int feet;
	float inches;

public:

	Distance() //конструктор (без аргументов)
	{
		feet = 0; inches = 0;
	}

	Distance(int ft, float in)//конструктор (2 аргумента)
	{
		feet = ft; inches = in;
	}

	void getdist()
	{
		cout << "\nвведите футы:"; cin >> feet;
		cout << "введите дюймы:"; cin >> inches;
	}

	void showdist() //вывод расстояния
	{
		cout << feet << "\' " << inches << '\"';
	}

	void add_dist(Distance d2, Distance d3)
	{
		inches = d2.inches + d3.inches;
		feet = 0;
		if (inches >= 12.0)
		{
			inches -= 12.0;
			feet++;
		}
		feet += d2.feet + d3.feet;
	}

	void div_dist(Distance d2, int divisor)
	{
		float fltfeet = d2.feet + d2.inches / 12.0;
		fltfeet /= divisor;
		feet = int(fltfeet);
		inches = (fltfeet - feet) * 12.0;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Distance distarr[100];
	Distance total(0, 0.0), average;
	int count = 0; 

	char ch; 

	do {
		cout << "\nвведите расстояние "; 
		distarr[count++].getdist(); 
		cout << "\nпродолжить (y/n)?"; 
		cin >> ch;
	} while (ch != 'n');

	for (int j = 0; j < count; j++)
		total.add_dist(total, distarr[j]); 

	average.div_dist(total, count); //разделить на число

	cout << "\n среднее:"; //вывести среднее значение

	average.showdist();
	cout << endl;
}
