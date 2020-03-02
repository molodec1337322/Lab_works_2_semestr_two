#include <iostream>

using namespace std;

class Matrix
{
private:
	const static int DEFAULT_WIDTH = 10;
	const static int DEFAULT_HEIGHT = 10;

	int width;
	int height;

	int matrix[DEFAULT_WIDTH][DEFAULT_HEIGHT];


public:
	Matrix(): width(DEFAULT_WIDTH), height(DEFAULT_HEIGHT)
	{}

	Matrix(int width, int height)
	{
		if (width >= 0 && width <= DEFAULT_WIDTH && height >= 0 && height <= DEFAULT_HEIGHT)
		{
			this->width = width;
			this->height = height;
		}
		else
		{
			throw exception();
		}
	}

	void PutEl(int x, int y, int val)
	{
		if (x >= 0 && x <= width && y >= 0 && y <= height)
		{
			matrix[x][y] = val;
		}
		else
		{
			throw exception();
		}
	}

	int GetEl(int x, int y) const
	{
		if (x >= 0 && x <= width && y >= 0 && y <= height)
		{
			return matrix[x][y];
		}
		else 
		{
			throw exception();
		}
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix mx(5, 5);
	mx.PutEl(1, 2, 15);
	cout << "Значение в ячейке (1, 2) равно: " << mx.GetEl(1, 2);
}
