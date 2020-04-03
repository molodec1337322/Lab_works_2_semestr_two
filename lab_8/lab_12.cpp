#include <iostream>

using namespace std;

class Sterling
{
protected:
	long pounds;
	int shillings;
	float penny;

	double decimalPounds;

	void ConvertFromDecimalToOldPounds()
	{
		double pennyTemp, temp1, temp2;

		penny = decimalPounds * 240;
		pounds = static_cast<long>(decimalPounds);
		pennyTemp = pounds * 240;
		temp1 = penny - pennyTemp;
		temp1 = static_cast<int>(temp1);
		shillings = temp1 / 12;
		shillings = static_cast<int>(shillings);
		temp2 = shillings * 12;
		penny = temp1 - temp2;
	}

	void ConvertFromOldToDecimalPounds()
	{
		decimalPounds = pounds + (penny / 12 + shillings) / 20;
	}

public:
	Sterling() : pounds(0), shillings(0), penny(0), decimalPounds(0.0)
	{}

	Sterling(double decimalPounds) :pounds(0), shillings(0), penny(0), decimalPounds(decimalPounds)
	{
		ConvertFromDecimalToOldPounds();
	}

	Sterling(long pounds, int shillings, float penny) : pounds(pounds), shillings(shillings), penny(penny), decimalPounds(0.0)
	{
		ConvertFromOldToDecimalPounds();
	}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "\n";
	}

	double GetDecimalPounds() const
	{
		return decimalPounds;
	}

	Sterling operator+(Sterling s)
	{
		double newDecimalPounds = decimalPounds + s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator-(Sterling s)
	{
		double newDecimalPounds = decimalPounds - s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(Sterling s)
	{
		double newDecimalPounds = decimalPounds / s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator*(double d)
	{
		double newDecimalPounds = decimalPounds * d;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(double d)
	{
		double newDecimalPounds = decimalPounds / d;
		return Sterling(newDecimalPounds);
	}
};


class Sterfac : public Sterling
{
private:
	int eights;

public:
	Sterfac() : Sterling(), eights(0)
	{}

	Sterfac(double decimalPounds) : Sterling(decimalPounds), eights(0)
	{}

	Sterfac(long pounds, int shillings, int penny, int eights) : Sterling(pounds, shillings, penny + eights / 8), eights(eights)
	{}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "-" << eights << "/8 \n";
	}

	void PutSterlingOld()
	{
		cout << "\nEnter sterling in old system";
		char dummychar;
		cin >> pounds >> dummychar >> shillings >> dummychar >> penny >> dummychar >> eights >> dummychar >> dummychar;
	}

	double GetDecimalPounds() const
	{
		return decimalPounds;
	}

	Sterfac operator+ (Sterfac s)
	{
		double newDecimalPounds = decimalPounds + s.decimalPounds;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator- (Sterfac s)
	{
		double newDecimalPounds = decimalPounds - s.decimalPounds;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator* (double d)
	{
		double newDecimalPounds = decimalPounds * d;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator/ (double d)
	{
		double newDecimalPounds = decimalPounds / d;
		return Sterfac(newDecimalPounds);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Sterfac pounds;
	pounds.PutSterlingOld();
	pounds.DisplaySterling();
}
