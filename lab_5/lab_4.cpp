#include <iostream>

using namespace std;

class Employee
{
private:
	int id;
	float salary;

public:
	Employee()
	{
		id = 0;
		salary = 0;
	}

	Employee(int id, float salary)
	{
		this->id = id;
		this->salary = salary;
	}

	void SetInfo(int id, float salary)
	{
		this->id = id;
		this->salary = salary;
	}

	void DisplayInfo()
	{
		cout << "id: " << id << " salary: " << salary << "\n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int id;
	float salary;
	const int employeesCount = 3;

	Employee employees[employeesCount];

	for(auto &employee : employees)
	{
		cout << "Введите данные сотрудника (номер, зарплата): ";
		cin >> id >> salary;
		employee.SetInfo(id, salary);
	}

	for (auto employee : employees)
	{
		employee.DisplayInfo();
	}
}
