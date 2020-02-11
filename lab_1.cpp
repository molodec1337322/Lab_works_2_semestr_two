//lab 1
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


//lab 2  
#include <iostream>
#include "stdlib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	for (int i = 1990; i < 1994; i++)
	{
		cout << i << "\t" << rand() << "\n";
	}
}
