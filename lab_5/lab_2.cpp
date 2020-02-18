#include <iostream>
#include <conio.h>

using namespace std;

class TollBooth

{

private:
	const double tax = 0.5;
	unsigned int totalCars; 
	double totalCash; 

public:

	TollBooth()
	{
		totalCars = 0;
		totalCash = 0;
	}

	void payingCar()
	{
		totalCars++; totalCash += tax;
	}

	void nopayCar()
	{
		totalCars++;
	}

	void display() const
	{
		cout << "\nММашины: " << totalCars << " Деньги: " << totalCash << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	TollBooth booth;
	const char ESCKey = 27;
	char userResponce;

	cout << "\nНажмите 0 для машины без оплаты," << "\n 1 для каждой оплачивающей машины," << "\n Esc для выхода.\n ";

	do {
		userResponce = _getche(); 
		if (userResponce == '0') 
		{
			booth.nopayCar();
		}
		else if (userResponce == '1')
		{
			booth.payingCar();
		}
	} while (userResponce != ESCKey);

	booth.display(); 
}
