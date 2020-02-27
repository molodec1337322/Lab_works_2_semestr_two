#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    void Lowterms()
    {
        long tnum, tden, temp, gcd;
        tnum = labs(numerator);
        tden = labs(denominator);
        if (tden == 0)
        {
            cout << "Недопустимый знаменатель";
            exit(1);
        }
        else if (tnum == 0)
        {
            numerator = 0;
            denominator = 1;
            return;
        }
        while (tnum != 0)
        {
            if (tnum < tden)
            {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }

        gcd = tden;
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

public:
    Fraction() : numerator(0), denominator(0)
    {}

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {
        Lowterms();
    }

    void SetFration(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int GetNumerator() const
    {
        return numerator;
    }

    int GetDenominator() const
    {
        return denominator;
    }

    Fraction operator + (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator + denominator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator - (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator - denominator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator * (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator / (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator;
        int newDenominator = denominator * fraction_2.numerator;

        return Fraction(newNumerator, newDenominator);
    }
};


int main()
{
	setlocale(LC_ALL, "Russian");
    const int size = 5;
    int numerator, denominator;
    char dummyChar;
    Fraction fractions[size];

    double average[size];
    double averageSum;

    for (int i = 0; i < size; i++)
    {
        cout << "Введите дробь: ";
        cin >> numerator >> dummyChar >> denominator;
        fractions[i].SetFration(numerator, denominator);
        average[i] = (double)numerator / (double)denominator;
        averageSum = average[i];
    }

    averageSum /= (double)size;
    cout << "Среднее значение: " << averageSum;
}
