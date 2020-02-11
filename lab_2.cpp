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
