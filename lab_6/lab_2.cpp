#include <iostream>
#include <string>

using namespace std;


class employee
{

private:
	string name;
	long number;

public:

	void getdata() 
	{
		cout << "\nвведите имя:"; 
		getline(cin, name);
		cout << "введите номер:"; 
		cin >> number;
	}

	void putdata()
	{
		cout << "\n имя:" << name;
		cout << "\n номер:" << number;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	employee emparr[100]; 
	int n = 0; 
	char ch; 

	do {
		cout << "\nвведите данные о работнике с номером " << n + 1;
		emparr[n++].getdata();
		cout << "продолжить (y/n)?"; 
		cin >> ch;
	} while (ch == 'y');

	for (int j = 0; j < n; j++) 
	{
		cout << "\nномер работника " << j + 1;
		emparr[j].putdata();
	}
	cout << endl;
}
