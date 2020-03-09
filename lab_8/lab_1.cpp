#include <iostream>

#include <string>

using namespace std;

////////////////////////////////////////////////////////////////

class Publication
{
private:
	string title;
	float price;

public:
	void GetData()
	{
		cout << "Введите название: ";
		cin >> title;
		cout << "Введите цену: ";
		cin >> price;
	}

	void PutData()
	{
		cout << "\nНазвание: " << title << " Цена: " << price;
	}
};


class Book : private Publication
{
private:
	int pages;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Введите количество страниц: ";
		cin >> pages;
	}

	void PutData()
	{
		Publication::PutData();
		cout << " Количество страниц: " << pages;
	}
};


class Tape : private Publication
{
private:
	float time;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Введите продолжительность: ";
		cin >> time;
	}

	void PutData()
	{
		Publication::PutData();
		cout << " Продолжительность: " << time;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Book book1; 
	Tape tape1;

	book1.GetData(); 
	tape1.GetData();
	book1.PutData();
	tape1.PutData();
	cout << endl;
	return 0;
}
