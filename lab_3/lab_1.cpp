#include <iostream>

using namespace std;

struct PhoneNumber
{
	int city;
	int station;
	int user;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	PhoneNumber myNumber = { 212, 767, 8900 };
	PhoneNumber userNumber;

	cout << "Введите ваш номер телефона: ";
	cin >> userNumber.city >> userNumber.station >> userNumber.user;

	cout << "номер телефона 1: " << myNumber.city << "-" << myNumber.station << "-" << myNumber.user;
	cout << "\nномер телефона 2: " << userNumber.city << "-" << userNumber.station << "-" << userNumber.user;
}