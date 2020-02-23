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

    int numerator, denominator;
    char dummyChar, userResponse, operation;
    Fraction fraction_1, fraction_2, fractionResult;

    do {
        cout << "Введите первую дробь: ";
        cin >> numerator >> dummyChar >> denominator;
        fraction_1.SetFration(numerator, denominator);

        cout << "Введите вторую дробь: ";
        cin >> numerator >> dummyChar >> denominator;
        fraction_2.SetFration(numerator, denominator);

        cout << "Введите действие: ";
        cin >> operation;

        switch (operation)
        {
        case '+':
            fractionResult = fraction_1 + fraction_2;
            break;

        case'-':
            fractionResult = fraction_1 - fraction_2;
            break;

        case '*':
            fractionResult = fraction_1 + fraction_2;
            break;

        case '/':
            fractionResult = fraction_1 + fraction_2;
            break;
        }

        cout << "Ответ: " << fractionResult.GetNumerator() << "/" << fractionResult.GetDenominator();
        cout << "\nПродолжить? (y/n): ";
        cin >> userResponse;
    } while (userResponse == 'y');
}
