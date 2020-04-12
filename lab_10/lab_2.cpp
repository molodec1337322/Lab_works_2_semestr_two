#include <iostream>

using namespace std;


class Publication
{
private:
	string title;
	float price;

public:
	virtual void GetData()
	{
		cout << "\nEnter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}

	virtual void PutData()
	{
		cout << "\n\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
};


class Book : public Publication
{
private:
	int pages;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Enter number of pages: ";
		cin >> pages;
	}

	void PutData()
	{
		Publication::PutData();
		cout << "\nPages: " << pages;
	}
};


class Tape : public Publication
{
private:
	float time;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Enter playing time: ";
		cin >> time;
	}

	void PutData()
	{
		Publication::PutData();
		cout << "\nTime: " << time;
	}
};


int main()
{
	const int SIZE = 100;
	Publication* pubsArr[SIZE];
	int n = 0; 

	char choice;

	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;
		if (choice == 'b') 
			pubsArr[n] = new Book; 
		else 
			pubsArr[n] = new Tape; 

		pubsArr[n++]->GetData();
		cout << " Enter another (y/n)? ";
		cin >> choice;
	}
	while (choice == 'y'); 

	for (int j = 0; j < n; j++) 
		pubsArr[j]->PutData(); 
	cout << endl;

	return 0;
}
