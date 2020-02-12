//lab 1
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int width = 10;
    const int height = 20;

    int userNum;
    cout << "Введите число: ";
    cin >> userNum;

    for (int i = 0; i < width * height; i++)
    {
        if (i % width == 0)
        {
            cout << "\n";
        }
        cout << setw(6) << userNum * i;  
    }
}



//lab 2
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    short userChoise;
    cout << "Введите 1 для перевода из шкалы фаренгейта в шкалу цельсия\nВведите 2 для перевода из шкалы цельсия в шкалу фаренгейта\n";
    cin >> userChoise;

    if(userChoise == 1)
    {
        float fahrenheit;
        cout << "Введите градусы по фаренгейту: ";
        cin >> fahrenheit;
        cout << "По цельсию это будет: " << (float)5 / 9 * (fahrenheit - 32);
    }
    else if(userChoise == 2)
    {
        float celcius;
        cout << "Введите градусы по цельсию: ";
        cin >> celcius;
        cout << "По фаренгейту это будет: " << (float)9 / 5 * celcius + 32;
    }
}




//lab 3
#include <iostream>
#include "conio.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char numChar;
    unsigned long num = 0;
    cout << "Введите число: ";
    while ((numChar = _getche()) != '\r')
    {
        num = num * 10 + numChar - 48;
    }
    cout << "\nВы ввели: " << num << endl;
}




//lab 4
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float firstNum, secondNum;
	char operand;
	bool isContinue = false;
	char userResponse;

	do{
		cout << "Введите первый операнд, операцию и второй операнд: ";
		cin >> firstNum >> operand >> secondNum;
		switch (operand)
		{
		case '+':
			cout << "Результат равен: " << firstNum + secondNum;
			break;
		case '-':
			cout << "Результат равен: " << firstNum - secondNum;
			break;
		case '*':
			cout << "Результат равен: " << firstNum * secondNum;
			break;
		case '/':
			cout << "Результат равен: " << firstNum / secondNum;
			break;
		default:
			cout << "\nТакого операда нет";
			break;
		}

		cout << "\nПродолжить y/n: ";
		cin >> userResponse;
		switch (userResponse)
		{
		case 'y':
			isContinue = true;
			break;
		case 'n':
			isContinue = false;
			break;
		default:
			cout << "Такого оператора нет";
			break;
		}
	} while (isContinue);
}
