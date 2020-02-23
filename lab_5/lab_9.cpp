#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(0)
    {}

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {}

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
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int numerator, denominator;
    char dummyChar, userResponse;
    Fraction fraction_1, fraction_2, fractionResult;

    do {
        cout << "Введите первую дробь: ";
        cin >> numerator >> dummyChar >> denominator;
        fraction_1.SetFration(numerator, denominator);

        cout << "Введите вторую дробь: ";
        cin >> numerator >> dummyChar >> denominator;
        fraction_2.SetFration(numerator, denominator);

        fractionResult = fraction_1 + fraction_2;
        cout << "Ответ: " << fractionResult.GetNumerator() << "/" << fractionResult.GetDenominator();
        cout << "\nПродолжить? (y/n): ";
        cin >> userResponse;
    } while (userResponse == 'y');
}
