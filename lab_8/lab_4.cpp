#include <iostream>

#include <string>

using namespace std;

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
		cout << "\nНазвание: " << title << " Цена: " << price << "\n";
	}
};


class Sales
{
private:
	static const int months = 3;
	float sales[months];

public:

	void GetData()
	{
		cout << "Введите продажи за 3 месяца:\n";
		for (int i = 0; i < months; i++)
		{
			cout << "Введите продажи за " << i + 1 << " месяц ";
			cin >> sales[i];
		}
	}

	void PutData()
	{
		for (int i = 0; i < months; i++)
		{
			cout << "Продажи за " << i + 1 << " месяц: " << sales[i] << "\n";
		}
	}
};


class Book : private Publication, Sales
{
private:
	int pages;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Введите количество страниц: ";
		cin >> pages;
		Sales::GetData();
	}

	void PutData()
	{
		Publication::PutData();
		cout << " Количество страниц: " << pages;
		Sales::PutData();
	}
};


class Tape : private Publication, Sales
{
private:
	float time;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Введите продолжительность: ";
		cin >> time;
		Sales::GetData();
	}

	void PutData()
	{
		Publication::PutData();
		cout << " Продолжительность: " << time;
		Sales::PutData();
	}
};


class Disk : private Publication, Sales
{
private:
	enum type {cd, dvd};
	type currentType;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Введите тип диска (с для cd и d для dvd):";
		char userResponce;
		cin >> userResponce;
		switch (userResponce)
		{
		case 'c':
			currentType = cd;
			break;

		case 'd':
			currentType = dvd;
			break;

		default:
			cout << "Такого варианта нет, поэтому выбран вариант по умолчанию (cd)\n";
			break;
		}
		Sales::GetData();
	}

	void PutData()
	{
		Publication::PutData();
		cout << "Тип диска: ";
		switch (currentType)
		{
		case cd:
			cout << "cd\n";
			break;

		case dvd:
			cout << "dvd\n";
			break;

		default:
			break;
		}
		Sales::PutData();
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Disk disk;
	disk.GetData();
	disk.PutData();
	return 0;
}
