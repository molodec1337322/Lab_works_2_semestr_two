#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int LIMIT = 100;
const int MAX = 100;

class Token 
{
public:

	virtual float getNumber() = 0;
	virtual char getOperand() = 0;
};

class Operand : public Token 
{
private:

	char _oper;

public:

	Operand(char oper) : _oper(oper) {}

	char getOperand()
	{
		return _oper;
	}

	float getNumber()
	{
		return 0;
	}
};

class Number : public Token
{
private:

	float _fnum;

public:

	Number(float fnum) : _fnum(fnum) {}

	float getNumber()
	{
		return _fnum;
	}

	char getOperand()
	{
		return 0;
	}
};

class Stack
{
private:

	Token* _arr[LIMIT];
	int _next;

public:

	Stack() : _next(0) {}

	void push(Token* el)
	{
		if (_next == LIMIT)
		{
			cout << "\nStack overflow\n";
			return;
		}
		_arr[_next++] = el;
	}

	Token* pop()
	{
		if (_next == 0)
		{
			cout << "\nStack is empty\n"; exit(0);
		}
		return _arr[--_next];
	}

	int count()
	{
		return _next;
	}
};

class express
{
private:

	Stack s;
	char* pStr;
	int len;

public:

	express(char* ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}

	float operation(float f1, float f2, char op)
	{
		switch (op)
		{
		case '+': return f1 + f2; break;
		case '-': return f1 - f2; break;
		case '*': return f1 * f2; break;
		case '/': return f1 / f2; break;
		default: cout << "\nНеизвестный оператор" << op; exit(1);
		}
	}

	bool isOperand(char ch)
	{
		return  ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}

	void parse()
	{
		char lastop, temp[MAX];
		float lastval, secval, buf;
		int k, j;
		for (j = 0, k = 0; j < len; j++)
		{
			if (isdigit(pStr[j]) || pStr[j] == ',')
			{
				temp[k++] = pStr[j];
			}
			else
			{
				temp[k] = '\0';
				k = 0;
				buf = stof(temp);
				s.push(new Number(buf));

				if (!isOperand(pStr[j]))
				{
					cout << "\nНеизвестный символ";
					exit(1);
				}
				if (s.count() == 1)
					s.push(new Operand(pStr[j]));
				else
				{
					lastval = s.pop()->getNumber();
					lastop = s.pop()->getOperand();
					if ((pStr[j] == '*' || pStr[j] == '/') && (lastop == '+' || lastop == '-'))
					{
						s.push(new Operand(lastop));
						s.push(new Number(lastval));
					}
					else
					{
						secval = s.pop()->getNumber();
						s.push(new Number(operation(secval, lastval, lastop)));
					}
					s.push(new Operand(pStr[j]));
				}
			}
		}
		temp[k] = '\0';
		buf = stof(temp);
		s.push(new Number(buf));
	}

	float solve()
	{
		float lastval, secval;
		char oper, oper2;
		while (s.count() > 2)
		{
			lastval = s.pop()->getNumber();
			oper = s.pop()->getOperand();
			secval = s.pop()->getNumber();
			if (s.count() != 0)
			{
				oper2 = s.pop()->getOperand();
				if (oper2 == '-')
				{
					secval *= -1;
					oper2 = '+';
				}
				s.push(new Operand(oper2));
			}
			s.push(new Number(operation(secval, lastval, oper)));
		}
		return s.pop()->getNumber();
	}
};


int main()
{
	setlocale(LC_ALL, "");
	char ans;
	char string[MAX];
	cout << "\nEnter an arithmetic expression"
		"\nof the form 2+3*4/3-2."
		"\nNo number may have more than one digit."
		"\nDon't use any spaces or parentheses.";

	do
	{
		cout << "\nEnter expresssion: "; 
		cin >> string;
		express* eptr = new express(string);
		eptr->parse();
		cout << "\nThe numerical value is: " << eptr->solve();
		delete eptr;
		cout << "\nDo another (Enter y or n)? ";
		cin >> ans;
	} while (ans == 'y');

	return 0;
}
