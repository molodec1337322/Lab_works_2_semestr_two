#include <iostream>

using namespace std;

class Angle
{
private:
	int degrees;
	float minutes;
	char direction;

public:
	Angle() : degrees(0), minutes(0.0), direction('N')
	{}

	Angle(int degrees, float minutes, char direction)
	{
		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}

	void SetAngle(int degrees, float minutes, char direction)
	{
		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}

	void ShowAngle()
	{
		cout << degrees << "°" << minutes << "'" << direction;
	}
};


class Ship
{
	static int number;

private:
	int id;
	Angle* pos_1;
	Angle* pos_2;

public:
	Ship() : id(++number), pos_1(new Angle), pos_2(new Angle)
	{}

	Ship(Angle pos_1, Angle pos_2) : id(++number), pos_1(&pos_1), pos_2(&pos_2)
	{}

	void ShowInfo()
	{
		cout << "Текущее местоположение корабля №" << id << ":\n";
		pos_1->ShowAngle();
		cout << "\n";
		pos_2->ShowAngle();
		cout << "\n\n";
	}

	void SetPosition(int degrees_1, float minutes_1, char direction_1, int degrees_2, float minutes_2, char direction_2)
	{
		pos_1->SetAngle(degrees_1, minutes_1, direction_1);
		pos_2->SetAngle(degrees_2, minutes_2, direction_2);
	}

	int GetID() const
	{
		return id;
	}
};
int Ship::number = 0;


int main()
{
    setlocale(LC_ALL, "Russian");

	Ship ships[1];
	int degrees_1, degrees_2;
	float minutes_1, minutes_2;
	char direction_1, direction_2, dummyChar;

	for (Ship ship : ships)
	{ 
		cout << "\nВведите положение " << ship.GetID() << " корабля (1) (d:m:D): ";
		cin >> degrees_1 >> dummyChar >> minutes_1 >> dummyChar >> direction_1;
		cout << "Введите положение " << ship.GetID() << " корабля (2) (d:m:D): ";
		cin >> degrees_2 >> dummyChar >> minutes_2 >> dummyChar >> direction_2;
		ship.SetPosition(degrees_1, minutes_1, direction_1, degrees_2, minutes_2, direction_2);
	}

	for (Ship ship : ships)
	{
		ship.ShowInfo();
	}
}
