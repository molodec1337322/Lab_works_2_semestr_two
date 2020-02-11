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



//lab 3
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int CONST = 10;
	int someVariable = CONST;
	cout << someVariable << "\n";
	someVariable *= 2;
	cout << someVariable << "\n";
	someVariable--;
	cout << someVariable;
}




//lab 4
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Мороз и солнце; день чудесный!\n" <<
		"Еще ты дремлешь, друг прелестный —\n" <<
		"Пора, красавица, проснись:\n" <<
		"Открой сомкнуты негой взоры";
}

//lab 5
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char character;
	cin >> character;
	if (islower(character))
	{
		cout << "строчная";
	}
	else
	{
		cout << "заглавная";
	}
}



//lab 6
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float poundSterling;
	cin >> poundSterling;
	const float toDollar = 1.487f;
	float dollars = poundSterling * toDollar;
	const float dollarTofrank = 0.172f;
	const float dollarToMark = 0.584f;
	const float dollatToYen = 0.00955f;

	cout << "dollars\t|\t" << dollars << endl;
	cout << "franks\t|\t" << dollars * dollarTofrank << endl;
	cout << "mark\t|\t" << dollars * dollarToMark << endl;
	cout << "yen\t|\t" << dollars * dollatToYen;
}



//lab 7
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int celcius;
	cin >> celcius;
	cout << "Фаренгейтов: " << (float)celcius * 9 / 5 + 32;
}



//lab 8
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << setfill('.') << "Москва"<< setw(8) <<"5461782";
}



//lab 9
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string firstNum, secondNum;

	cout << "Введите первую дробь: ";
	cin >> firstNum;

	cout << "\nВведите вторую дробь: ";
	cin >> secondNum;

	size_t slashPos;
	for (size_t i = 0; i < firstNum.size(); i++)
	{
		if (firstNum[i] == '/')
		{
			slashPos = i;
			break;
		}
	}

	int firstNumHalves[2] = {atoi(firstNum.substr(0, slashPos).c_str()),  atoi(firstNum.substr(slashPos + 1, firstNum.size()).c_str())};

	for (size_t i = 0; i < secondNum.size(); i++)
	{
		if (secondNum[i] == '/')
		{
			slashPos = i;
			break;
		}
	}

	int secondNumHalves[2] = { atoi(secondNum.substr(0, slashPos).c_str()), atoi(secondNum.substr(slashPos + 1, secondNum.size()).c_str())};

	int upperHalf = firstNumHalves[0] * secondNumHalves[1] + secondNumHalves[0] * firstNumHalves[1];
	int bottomHalf = firstNumHalves[1] * secondNumHalves[1];

	cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
}




//lab 10
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int pennyToShillings = 12;
	const int shillingsToPounds = 20;

	float penny, shillings, pounds;
	cout << "Введите количество пенсов: ";
	cin >> penny;
	cout << "Введите количество шиллингов: ";
	cin >> shillings;
	cout << "Введите количество фунтов: ";
	cin >> pounds;

	float decimalPounds = pounds + (penny / pennyToShillings + shillings) / shillingsToPounds;

	cout << "Десятичных фунтов: " << decimalPounds;
}

//lab 11
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << setiosflags(ios::left) << setfill(' ') << setw(10) << "Фамилия"
		<< setfill(' ') << setw(10) << "Имя"
		<< setfill(' ') << setw(15) << "Адрес"
		<< setfill(' ') << setw(12) << "Город" << "\n\n"
		<< setfill(' ') << setw(10) << "Петров"
		<< setfill(' ') << setw(10) << "Василий"
		<< setfill(' ') << setw(15) << "Кленовая 16"
		<< setfill(' ') << setw(12) << "Питер" << "\n"
		<< setfill(' ') << setw(10) << "Иванов"
		<< setfill(' ') << setw(10) << "Сергей"
		<< setfill(' ') << setw(15) << "Осиновая 3"
		<< setfill(' ') << setw(12) << "Находка" << "\n"
		<< setfill(' ') << setw(10) << "Сидоров"
		<< setfill(' ') << setw(10) << "Иван"
		<< setfill(' ') << setw(15) << "Березовая 21"
		<< setfill(' ') << setw(12) << "Калиниград" << "\n";
}





//lab 12
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float decimalPound, Penny_1, Pennny_2, temp_1, temp_2, shilling, penny;
    cout << "Ведите число десятичных фунтов ";
    cin >> decimalPound;

    Penny_1 = decimalPound * 240;
    decimalPound = static_cast<int>(decimalPound);
    Pennny_2 = decimalPound * 240;
    temp_1 = Penny_1 - Pennny_2;
    temp_1 = static_cast<int>(temp_1);
    shilling = temp_1 / 12;
    shilling = static_cast<int>(shilling);
    temp_2 = shilling * 12;
    penny = temp_1 - temp_2;

    cout << "Фунтов в старой системе: " << decimalPound << "." << shilling << "." << penny << endl;
}
