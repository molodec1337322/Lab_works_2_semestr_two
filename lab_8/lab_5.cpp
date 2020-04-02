#include <iostream>

using namespace std;

class employee //employee class
{
private:
	static const int LEN = 50;
	char name[LEN]; //employee name
	unsigned long number; //employee number

public:
	void getdata()
	{
		cout << "\n Enter last name: "; cin >> name;
		cout << " Enter number: "; cin >> number;
	}

	void putdata() const
	{
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}
};


class Employee2 : private employee
{
private:
	enum salaryType {hour, week, month};
	salaryType currentSalaryType;
	double compensation;

public:
	void GetData()
	{
		employee::getdata();

		cout << " Enter salary:";
		cin >> compensation;

		cout << " Enter salary type (h - per hour, w - per week, m - per month):";
		char userResponce;
		cin >> userResponce;
		switch (userResponce)
		{
		case 'h':
			currentSalaryType = hour;
			break;

		case 'w':
			currentSalaryType = week;
			break;

		case 'm':
			currentSalaryType = month;
			break;

		default:
			break;
		}
	}

	void PutData()
	{
		employee::putdata();
		cout << "\n Salary: " << compensation;
		cout << "\n Salary type: ";
		switch (currentSalaryType)
		{
		case hour:
			cout << "per hour";
			break;

		case week:
			cout << "per week";
			break;

		case month:
			cout << "per month";
			break;

		default:
			break;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Employee2 employee;
	employee.GetData();
	employee.PutData();

}
