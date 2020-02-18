#include <iostream>

using namespace std;

class Distance 
{
private:
	int feet;
	float inches;

public:

	Distance() : feet(0), inches(0.0)
	{} 

	Distance(int ft, float in) : feet(ft), inches(in)
	{}

	void getdist() 
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}

	void showdist() const 
	{
		cout << feet << "\' " << inches << '\"';
	}

	Distance operator + (Distance distance_2) const
	{
		int f = feet + distance_2.feet;
		float i = inches + distance_2.inches;

		if (i >= 12.0)
		{
			i -= 12.0;
			f++;
		}

		return Distance(f, i);
	}

	Distance operator - (Distance distance_2) const
	{
		int feet = this->feet - distance_2.feet;
		float inches = this->inches - distance_2.inches;

		if (inches < 0.0)
		{
			inches += 12.0;
			feet--;
		}

		return Distance(feet, inches);
	}
};



int main()

{

	Distance dist1, dist3, dist4; 
	dist1.getdist(); 

	Distance dist2(11, 6.25); 

	dist3 = dist1 + dist2; 
	dist4 = dist1 + dist2 + dist3; 


	cout << "dist1 = "; dist1.showdist(); cout << endl;
	cout << "dist2 = "; dist2.showdist(); cout << endl;
	cout << "dist3 = "; dist3.showdist(); cout << endl;
	cout << "dist4 = "; dist4.showdist(); cout << endl;

	dist3 = dist1 - dist2;

	cout << "dist1 = "; dist1.showdist(); cout << endl;
	cout << "dist2 = "; dist2.showdist(); cout << endl;
	cout << "dist3 = "; dist3.showdist(); cout << endl;
}
