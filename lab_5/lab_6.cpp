#include <iostream>

using namespace std;

enum Type {
	laborer, secretary, manager,
	accountant, executive, researcher, None
};

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date() : year(0), month(0), day(0)
	{}

	Date(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	void ShowDate()
	{
		cout << "Текущая дата: " << month << "/" << day << "/" << year;
	}
};


class Employee
{
private:
	int id;
	float salary;
	Date dateWorking;
	Type type;

public:
	Employee()
	{
		id = 0;
		salary = 0;
		dateWorking.SetDate(0, 0, 0);
		type = Type::None;
	}

	Employee(int id, float salary, Date dateWorking, Type type)
	{
		this->id = id;
		this->salary = salary;
		this->dateWorking = dateWorking;
		this->type = type;
	}

	void SetInfo(int id, float salary, Date dateWorking, Type type)
	{
		this->id = id;
		this->salary = salary;
		this->dateWorking = dateWorking;
		this->type = type;
	}

	void DisplayInfo()
	{
		cout << "id: " << id << " salary: " << salary; dateWorking.ShowDate();
		switch (type)
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
		cout << "\n";
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	int id, day, month, year;
	float salary;
	char userType, dummyChar;
	Type employeeType;
	const int employeesCount = 3;

	Employee employees[employeesCount];
	Date startWorkDate;

	for (auto& employee : employees)
	{
		cout << "Введите данные сотрудника (номер, зарплата): ";
		cin >> id >> salary;
		cout << "Введите дату приема на работу (mm/dd/yyyy): ";
		cin >> month >> dummyChar >> day >> dummyChar >> year;
		startWorkDate.SetDate(year, month, day);
		cout << "Введите должность сотрудника по первой букве:";
		cin >> userType;

		switch (userType)
		{
		case 'l':
			employeeType = laborer;
			break;
		case 's':
			employeeType = secretary;
			break;
		case 'm':
			employeeType = manager;
			break;
		case 'a':
			employeeType = accountant;
			break;
		case 'e':
			employeeType = executive;
			break;
		case 'r':
			employeeType = researcher;
			break;
		}

		employee.SetInfo(id, salary, startWorkDate, employeeType);
	}

	for (auto employee : employees)
	{
		employee.DisplayInfo();
	}
}
