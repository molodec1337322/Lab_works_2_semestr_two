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
	Tape tape;
	tape.GetData();
	tape.PutData();

	return 0;
}
