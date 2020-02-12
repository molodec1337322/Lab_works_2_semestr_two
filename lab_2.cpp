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






//lab 5
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int height = 20;
	char pyramidChar = 'X';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << pyramidChar;
		}
		cout << "\n";
	}
}





//lab 6
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int userNum, result;

	while (true)
	{
		cout << "\nВведите число: ";
		cin >> userNum;

		if (userNum == 0)
		{
			break;
		}
		else
		{
			result = 1;
			for (int i = userNum; i > 0; i--)
			{
				result *= i;
			}

			cout << "Факториал равен: " << result;
		}
	}
}





//lab 7
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float startMoney, money, percents;
    int years;

    cout << "Введите начальный вклад: ";
    cin >> startMoney;
    cout << "Введите число лет: ";
    cin >> years;
    cout << "Введите процентную ставку: ";
    cin >> percents;

    money = startMoney;
    for (int i = 0; i < years; i++)
    {
        money = money + (money * percents / 100);
    }

    cout << "Через " << years << "лет вы получите: " << money;

}





//lab 8
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int pounds_1, pounds_2, shillings_1, shillings_2, penny_1, penny_2;
    int poundsResult, shillingsResult, pennyResult;
    const int pennyInShilling = 12;
    const int shillingsInPound = 20;
    char userResponse;

    do {
        cout << "Введите первую сумму: ";
        cin >> pounds_1 >> shillings_1 >> penny_1;
        cout << "Введите вторую сумму: ";
        cin >> pounds_2 >> shillings_2 >> penny_2;

        poundsResult = pounds_1 + pounds_2;
        shillingsResult = shillings_1 + shillings_2;
        pennyResult = penny_1 + penny_2;

        shillingsResult = shillingsResult + pennyResult / pennyInShilling;
        pennyResult %= pennyInShilling;
        poundsResult = poundsResult + shillingsResult / shillingsInPound;
        shillingsResult %= shillingsInPound;

        cout << "Всего: " << poundsResult << " " << shillingsResult << " " << pennyResult;

        cout << "\nПродолжить? y/n: ";
        cin >> userResponse;

    } while (userResponse == 'y');
}
