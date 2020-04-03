#include <iostream>

using namespace std;

const int LEN = 80; 


class student //educational background
{
private:
	char school[LEN]; //name of school or university
	char degree[LEN]; //highest degree earned

public:
	void getedu()
	{
		cout << " Enter name of school or university: ";
		cin >> school;
		cout << " Enter highest degree earned \n";
		cout << " (Highschool, Bachelor's, Master's, PhD): ";
		cin >> degree;
	}

	void putedu() const
	{
		cout << "\n School or university: " << school;
		cout << "\n Highest degree earned: " << degree;
	}
};


class employee
{
private:
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


class manager : private employee, private student //management
{
private:
	char title[LEN]; //"vice-president" etc.
	double dues; //golf club dues

public:
	void getdata()
	{
		employee::getdata();
		cout << " Enter title: "; cin >> title;
		cout << " Enter golf club dues: "; cin >> dues;
		student::getedu();
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n Title: " << title;
		cout << "\n Golf club dues: " << dues;
		student::putedu();
	}
};


class scientist : private employee, private student //scientist
{
private:
	int pubs; //number of publications

public:
	void getdata()
	{
		employee::getdata();
		cout << " Enter number of pubs: "; cin >> pubs;
		student::getedu();
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n Number of publications: " << pubs;
		student::putedu();
	}
};


class laborer : public employee 
{

};


class Executive : private manager
{
private:
	double award;
	int companyShares;

public:
	void GetData()
	{
		manager::getdata();
		cout << " Enter executive award: ";
		cin >> award;
		cout << " Enter number of campany shares: ";
		cin >> companyShares;
	}

	void PutData()
	{
		manager::putdata();
		cout << "\n Executive award: " << award;
		cout << "\n Executive company shares: " << companyShares;
	}
};


int main()
{
	Executive exec;
	exec.GetData();
	exec.PutData();
	return 0;
}
