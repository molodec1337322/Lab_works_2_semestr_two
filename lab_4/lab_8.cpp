#include <iostream>

using namespace std;

void swap(int& firstNum, int& secondNum) {
	int temp;
	temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int firstNum, secondNum;
	cout << "Введите два целых значения : \n";
	cin >> firstNum >> secondNum;
	swap(firstNum, secondNum);
	cout << firstNum << " " << secondNum << endl;
}
