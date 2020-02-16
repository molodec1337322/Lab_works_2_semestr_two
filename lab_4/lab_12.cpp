#include <iostream>

using namespace std;

struct Fraction 
{
	int a;
	int b;
};

Fraction fadd(Fraction firstFraction, Fraction secondFraction) 
{
	Fraction result;

	result.a = firstFraction.a * secondFraction.b + firstFraction.b * secondFraction.a;
	result.b = firstFraction.b * secondFraction.b;

	return result;
}

Fraction fsub(Fraction firstFraction, Fraction secondFraction) 
{
	Fraction result;

	result.a = firstFraction.a * secondFraction.b - firstFraction.b * secondFraction.a;
	result.b = firstFraction.b * secondFraction.b;

	return result;
}

Fraction fmul(Fraction firstFraction, Fraction secondFraction) 
{
	Fraction result;

	result.a = firstFraction.a * secondFraction.a;
	result.b = firstFraction.b * secondFraction.b;

	return result;
}

Fraction fdiv(Fraction firstFraction, Fraction secondFraction) 
{
	Fraction result;

	result.a = firstFraction.a * secondFraction.b;
	result.b = firstFraction.b * secondFraction.a;

	return result;
}

int main()
{
	Fraction firstFraction, secondFraction, result;
	char dummyChar;
	char sign;

	cout << "Введите первую дробь (a/b) : ";
	cin >> firstFraction.a >> dummyChar >> firstFraction.b;

	cout << "Введите операцию : ";
	cin >> sign;

	cout << "Введите вторую дробь (c/d) : ";
	cin >> secondFraction.a >> dummyChar >> secondFraction.b;

	switch (sign)
	{
	case '+': 
		result = fadd(firstFraction, secondFraction); 
		break;

	case '-': 
		result = fsub(firstFraction, secondFraction); 
		break;

	case '*': 
		result = fmul(firstFraction, secondFraction); 
		break;

	case '/': 
		result = fdiv(firstFraction, secondFraction); 
		break;
	}
}
