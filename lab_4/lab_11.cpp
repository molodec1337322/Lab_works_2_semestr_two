#include <iostream>

using namespace std;

struct Sterling 
{
	int pounds;
	int shillings;
	int penny;
};

Sterling enter(Sterling sterling) 
{

	cout << "Введите количество фунтов : ";
	cin >> sterling.pounds;
	cout << "Введите количество шиллингов : ";
	cin >> sterling.shillings;
	cout << "Введите количество пенсов : ";
	cin >> sterling.penny;

	return sterling;
}

Sterling sum(Sterling firstSterling, Sterling secondSterling) 
{
	Sterling result;

	result.penny = firstSterling.penny + secondSterling.penny;
	result.shillings = firstSterling.shillings + secondSterling.shillings + result.penny / 12;
	result.penny %= 12;
	result.pounds = firstSterling.pounds + secondSterling.pounds + result.shillings / 20;
	result.shillings %= 20;

	return result;
}

void print(Sterling sterling) 
{
	cout << sterling.pounds << " " << sterling.shillings << " " << sterling.penny << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Sterling user = {0, 0, 0};

	Sterling firstSterling = enter(user);
	Sterling secondSterling = enter(user);

	print(sum(firstSterling, secondSterling));
}
