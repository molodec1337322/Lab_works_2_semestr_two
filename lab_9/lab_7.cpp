#include <iostream>
#include <string> //for string class

using namespace std;


class person 
{
protected:
	string name; 
	float salary;

public:
	void setData() 
	{
		cout << "Enter name: "; 
		cin >> name;
		cout << "Enter salary: ";
		cin >> salary;
	}

	void printData() 
	{
		cout << "\nname: " << name << " salary: " << salary;
	}

	string getName() 
	{
		return name;
	}

	float getSalary()
	{
		return salary;
	}
};


void orderByName(person** pp1, person** pp2)
{
	if ((*pp1)->getName() > (*pp2)->getName())
	{
		person* tempptr = *pp1; //swap the pointers
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}


void orderBySalary(person** pp1, person** pp2)
{
	if ((*pp1)->getSalary() > (*pp2)->getSalary())
	{
		person* tempptr = *pp1; //swap the pointers
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}


void bsort(person** pp, int n, void order(person**, person**))
{
	int j, k;
	for (j = 0; j < n - 1; j++)
		for (k = j + 1; k < n; k++)
			order(pp + j, pp + k);
}


int main()
{
	person* persPtr[100]; //array of pointers to persons

	int n = 0; //number of persons in array

	char choice; //input char

	do { //put persons in array
		persPtr[n] = new person; //make new object
		persPtr[n]->setData(); //set person's name
		n++; //count new person
		cout << "Enter another (y/n)? "; //enter another
		cin >> choice; // person?
	}
	while (choice == 'y'); //quit on 'n'

	cout << "\nUnsorted list:";

	for (int j = 0; j < n; j++) 
	{
		persPtr[j]->printData();
	}

	bsort(persPtr, n, orderByName); 
	cout << "\n\nSorted list by name:";
	for (int j = 0; j < n; j++) 
	{
		persPtr[j]->printData();
	}
	cout << endl;

	bsort(persPtr, n, orderBySalary);
	cout << "\n\nSorted list by salary:";
	for (int j = 0; j < n; j++)
	{
		persPtr[j]->printData();
	}
	cout << endl;

	return 0;
} 
