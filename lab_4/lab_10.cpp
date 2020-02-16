#include <iostream>

using namespace std;

void function(int counter)
{
	cout << "функция вызвалась " << counter << " раз\n";
	if (counter < 10)
	{
		function(++counter);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	function(0);
}
