#include <iostream>

using namespace std;


class Publication
{
protected:
	string title;
	float price;
	bool isOversized;

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

	virtual void GetIsOversized()
	{
		if (isOversized)
		{
			cout << "\nOversized";
		}
		else
		{
			cout << "\nNot oversized";
		}
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
		if (pages > 800)
		{
			isOversized = true;
		}
		else
		{
			isOversized = false;
		}
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
		if (time > 90)
		{
			isOversized = true;
		}
		else
		{
			isOversized = false;
		}
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
	} while (choice == 'y');

	for (int j = 0; j < n; j++)
	{
		pubsArr[j]->PutData();
		pubsArr[j]->GetIsOversized();
	}
	cout << endl;

	return 0;
}
