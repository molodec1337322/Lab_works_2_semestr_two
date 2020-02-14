#include <iostream>

using namespace std;

enum type {
	laborer, secretary, manager,
	accountant, executive, researcher
};

struct Date
{
	int month;
	int day;
	int year;
};

struct Employee
{
	int id;
	float salary;
	Date date;
	type etype;
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Employee employees[3];
	char dummyChar;
	char employeeType;

	for (int i = 0; i < 3; i++)
	{
		cout << "Введите индетикафикационный сотрудника номер " << i << " : ";
		cin >> employees[i].id;
		cout << "Введите зарплату сотрудника номер " << i << " : ";
		cin >> employees[i].salary;
		cout << "Дата принятия на работу (мм/дд/гггг): ";
		cin >> employees[i].date.month >> dummyChar >> employees[i].date.day >> dummyChar >> employees[i].date.year;
		cout << "Введите должность (laborer, secretary, manager, accountant, executive, researcher): ";
		cin >> employeeType;
		switch (employeeType)
		{
		case 'l':
			employees[i].etype = laborer;
			break;
		case 's':
			employees[i].etype = secretary;
			break;
		case 'm':
			employees[i].etype = manager;
			break;
		case 'a':
			employees[i].etype = accountant;
			break;
		case 'e':
			employees[i].etype = executive;
			break;
		case 'r':
			employees[i].etype = researcher;
			break;
		}
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "\nЗарплата сотрудника под номером " << employees[i].id << " " << employees[i].salary;
		cout << "\nОн устроился " << employees[i].date.month << "/" << employees[i].date.year << "/" << employees[i].date.year;
		cout << "\nОн является ";
		switch (employees[i].etype)
		{
		case laborer:
			cout << "laborer";
			break;
		case secretary:
			cout << "secretary";
			break;
		case manager:
			cout << "manager";
			break;
		case accountant:
			cout << "accountant";
			break;
		case executive:
			cout << "execitive";
			break;
		case researcher:
			cout << "reseracher";
			break;
		}
	}	
}
