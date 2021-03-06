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





//lab 9
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int guestsCount, freeChairs;
    int temp;

    cout << "Введите количество гостей: ";
    cin >> guestsCount;
    cout << "Введите количество мест: ";
    cin >> freeChairs;

    if (guestsCount < freeChairs)
    {
        cout << "Количество гостей не может быть меньше стульев";
    }
    else
    {
        temp = 1;
        for (int i = guestsCount; i > guestsCount - freeChairs; i--)
        {
            temp *= i;
        }

        cout << "Количестов способов рассадки: " << temp;
    }
}




//lab 10
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float years = 0;
    float money, needMoney, percents;

    cout << "Введите стартовую сумму: ";
    cin >> money;
    cout << "Введите необходимую сумму: ";
    cin >> needMoney;
    cout << "Введите процентную ставку: ";
    cin >> percents;

    while (money <= needMoney)
    {
        money = money + (money * percents / 100);
        years++;
    }

    cout << "Необходимая сумма будет через: " << (int)years;
}






//lab 11
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int pounds_1, pounds_2, shillings_1, shillings_2, penny_1, penny_2;
    int poundsResult, shillingsResult, pennyResult;
    const int pennyInShilling = 12;
    const int shillingsInPound = 20;
    char userResponseToContinue;
    char userResponceOperation;

    do {
        cout << "Введите действие: ";
        cin >> userResponceOperation;

        switch (userResponceOperation)
        {
        case '+':
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

            break;

        case '-':
            cout << "Введите первую сумму: ";
            cin >> pounds_1 >> shillings_1 >> penny_1;
            cout << "Введите вторую сумму: ";
            cin >> pounds_2 >> shillings_2 >> penny_2;

            poundsResult = pounds_1 - pounds_2;
            shillingsResult = shillings_1 - shillings_2;
            pennyResult = penny_1 - penny_2;

            if (pennyResult < 0)
            {
                shillingsResult--;
                pennyResult = pennyInShilling - pennyResult;
            }
            if (shillingsResult < 0)
            {
                poundsResult--;
                shillingsResult = shillingsInPound - shillingsResult;
            }

            cout << "Всего: " << poundsResult << " " << shillingsResult << " " << pennyResult;

            break;

        case '*':
            int multiplier;
            cout << "Введите первую сумму: ";
            cin >> pounds_1 >> shillings_1 >> penny_1;
            cout << "Введите во сколько раз надо увеличить указанную сумму: ";
            cin >> multiplier;

            poundsResult = pounds_1 * multiplier;
            shillingsResult = shillings_1 * multiplier;
            pennyResult = penny_1 * multiplier;

            shillingsResult = shillingsResult + pennyResult / pennyInShilling;
            pennyResult %= pennyInShilling;
            poundsResult = poundsResult + shillingsResult / shillingsInPound;
            shillingsResult %= shillingsInPound;

            cout << "Всего: " << poundsResult << " " << shillingsResult << " " << pennyResult;

            break;

        default:
            cout << "Такого действия нет\n";
            break;
        }

        cout << "\nПродолжить? y/n: ";
        cin >> userResponseToContinue;

    } while (userResponseToContinue == 'y');
}






//lab 12
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int firstNumHalves[2];
	int secondNumHalves[2];
	int upperHalf, bottomHalf;
	char userResponceToContinue;
	char userResponceOperation;

	string firstNum, secondNum;

	do {
		cout << "Введите первую дробь: ";
		cin >> firstNum;
		cout << "Введите вторую дробь: ";
		cin >> secondNum;
		cout << "Введите действие: ";
		cin >> userResponceOperation;

		size_t slashPos;
		for (size_t i = 0; i < firstNum.size(); i++)
		{
			if (firstNum[i] == '/')
			{
				slashPos = i;
				break;
			}
		}

		firstNumHalves[0] = atoi(firstNum.substr(0, slashPos).c_str()); 
		firstNumHalves[1] = atoi(firstNum.substr(slashPos + 1, firstNum.size()).c_str());

		for (size_t i = 0; i < secondNum.size(); i++)
		{
			if (secondNum[i] == '/')
			{
				slashPos = i;
				break;
			}
		}

		secondNumHalves[0] = atoi(secondNum.substr(0, slashPos).c_str());
		secondNumHalves[1] = atoi(secondNum.substr(slashPos + 1, secondNum.size()).c_str());

		switch (userResponceOperation)
		{
		case '+':
			upperHalf = firstNumHalves[0] * secondNumHalves[1] + secondNumHalves[0] * firstNumHalves[1];
			bottomHalf = firstNumHalves[1] * secondNumHalves[1];
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '-':
			upperHalf = firstNumHalves[0] * secondNumHalves[1] - secondNumHalves[0] * firstNumHalves[1];
			bottomHalf = firstNumHalves[1] * secondNumHalves[1];
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '*':
			upperHalf = firstNumHalves[0] * secondNumHalves[0];
			bottomHalf = firstNumHalves[1] * secondNumHalves[1];
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		case '/':
			upperHalf = firstNumHalves[0] * secondNumHalves[1];
			bottomHalf = firstNumHalves[1] * secondNumHalves[0];
			cout << "\nРезультат равен: " << upperHalf << "/" << bottomHalf;
			break;

		default:
			cout << "Такого действия не существует\n";
			break;
		}

		cout << "\nХотите продолжить? (y/n): ";
		cin >> userResponceToContinue;

	} while (userResponceToContinue == 'y');
}
