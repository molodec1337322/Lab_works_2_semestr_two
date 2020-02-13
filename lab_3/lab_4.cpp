#include <iostream>

using namespace std;

struct Employee
{
	int id;
	float salary;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Employee employees[3];

	for (int i = 0; i < 3; i++)
	{
		cout << "Введите индетикафикационный сотрудника номер " << i << " : ";
		cin >> employees[i].id;
		cout << "Введите зарплату сотрудника номер " << i << " : ";
		cin >> employees[i].salary;
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Зарплата сотрудника под номером " << employees[i].id << " " << employees[i].salary << "\n";
	}
}