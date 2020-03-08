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

    bool operator == (Fraction fraction_2)
    {
        return numerator == fraction_2.numerator && denominator == fraction_2.denominator ? true : false;
    }

    bool operator != (Fraction fraction_2)
    {
        return numerator == fraction_2.numerator && denominator == fraction_2.denominator ? false : true;
    }
};


bool IsStopFraction(Fraction stopFraction, Fraction f)
{
    return stopFraction == f;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Fraction userFraction_1, userFraction_2, resultFraction;
    const Fraction stopFraction(0, 1);

    int numerator, denominator;
    char ch, userOperation;

    while (true)
    {
        cout << "Введите дробь 1: ";
        cin >> numerator >> ch >> denominator;
        userFraction_1.SetFration(numerator, denominator);
        if (IsStopFraction(stopFraction, userFraction_1)) break;

        cout << "Введите дробь 2: ";
        cin >> numerator >> ch >> denominator;
        userFraction_2.SetFration(numerator, denominator);
        if (IsStopFraction(stopFraction, userFraction_2)) break;

        cout << "Введите действие: ";
        cin >> userOperation;

        switch (userOperation) 
        {
        case '+':
            resultFraction = userFraction_1 + userFraction_2;
            break;
        case '-':
            resultFraction = userFraction_1 - userFraction_2;
            break;
        case '*':
            resultFraction = userFraction_1 * userFraction_2;
            break;
        case '/':
            resultFraction = userFraction_1 / userFraction_2;
            break;
        }

        cout << resultFraction.GetNumerator() << "/" << resultFraction.GetDenominator() << "\n\n";
    }
}
