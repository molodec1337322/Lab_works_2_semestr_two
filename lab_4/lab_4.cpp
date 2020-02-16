#include <iostream>

using namespace std;

struct Distance {
	int feet;
	float inches;
};

Distance bigend(Distance distance_1, Distance distance_2) {
	if (distance_1.feet > distance_2.feet) return distance_1;
	if (distance_1.feet < distance_2.feet) return distance_2;

	if (distance_1.inches > distance_2.inches) return distance_1;
	else return distance_2;
}

void engldisp(Distance distance) {
	cout << distance.feet << "\'-" << distance.inches << "\"" << endl;
}

int main()
{
	Distance d1, d2, d3;
	setlocale(LC_ALL, "Rus");

	cout << "Введите число фунтов 1: ";
	cin >> d1.feet;
	cout << "Введите число дюймов 1: ";
	cin >> d1.inches;

	cout << "Введите число фунтов 2: ";
	cin >> d2.feet;
	cout << "Введите число дюймов 2: ";
	cin >> d2.inches;

	d3 = bigend(d1, d2);
	cout << "d1 = "; engldisp(d1);
	cout << "d2 = "; engldisp(d2);
}
