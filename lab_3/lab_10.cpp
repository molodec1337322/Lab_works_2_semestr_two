#include <iostream>

using namespace std;

struct Sterling
{
	int pounds;
	int shillings;
	int penny;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Sterling sterling;
	double newPounds;
	double penny_1, penny_2, temp_1, temp_2;

	cout << "Введите сумму в новых фунтах: ";
	cin >> newPounds;

	penny_1 = newPounds * 240;
	sterling.pounds = static_cast<int>(newPounds);
	penny_2 = sterling.pounds * 240;
	temp_1 = penny_1 - penny_2;
	temp_1 = static_cast<int>(temp_1);
	sterling.shillings = temp_1 / 12;
	sterling.shillings = static_cast<int>(sterling.shillings);
	temp_2 = sterling.shillings * 12;
	sterling.penny = temp_1 - temp_2;

	cout << "Фунтов в старой системе: " << sterling.pounds << "." << sterling.shillings << "." << sterling.penny << endl;
}
