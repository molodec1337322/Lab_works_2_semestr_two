#include <iostream>

using namespace std;

class Distance 
{
private:
	int feet;
	float inches;

public:

	Distance() 
	{
		feet = 0; inches = 0;
	}

	Distance(int ft, float in)
	{
		feet = ft; inches = in;
	}

	void getdist()
	{
		cout << "\nвведите футы:"; cin >> feet;
		cout << "введите дюймы:"; cin >> inches;
	}

	void showdist() 
	{
		cout << feet << "\' " << inches << '\"';
	}

	Distance operator+(Distance d2)
	{
		float newInches = inches + d2.inches;
		int newFeet = inches + d2.inches;
		if (newInches >= 12.0)
		{
			newInches -= 12.0;
			newFeet++;
		}

		return Distance(newFeet, newInches);
	}

	Distance operator-(Distance d2)
	{
		float newInches = inches - d2.inches;
		int newFeet = inches + d2.inches;
		if (newInches < 0.0)
		{
			newInches += 12.0;
			newFeet--;
		}

		return Distance(newFeet, newInches);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Distance dist1, dist3; 
	dist1.getdist(); 
	Distance dist2(3, 6.25); 

	dist3 = dist1 - dist2; 

	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
}
