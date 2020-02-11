#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	const float gallonsToCubicFeets = 7.481f;
	int feets;
	std::cout << "Введите кол-во галлонов: ";
	std::cin >> feets;
	std::cout << "\nКубических фунтов: " << gallonsToCubicFeets * feets;
}
