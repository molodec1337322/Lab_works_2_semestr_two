#include <iostream>
#include <stack>

using namespace std;


class Token
{
public:
	virtual float GetNumber() = 0;
	virtual char GetOperator() = 0;
};


class Operator : public Token
{
private:
	char op;

public:
	Operator(char op): op(op)
	{}

	float GetNumber() override
	{
		return NULL;
	}

	char GetOperator() override
	{
		return op;
	}
};


class Number : public Token
{
private:
	float num;

public:
	Number(float num) : num(num)
	{}

	float GetNumber() override
	{
		return num;
	}

	char GetOperator() override
	{
		return NULL;
	}
};

int main() 
{
	stack<Token*> s;
	s.push(new Number(7));
	s.push(new Operator('-'));
	s.push(new Number(6));

	
	cout << s.top()->GetNumber() << s.top()->GetOperator();
	s.pop();
	cout << s.top()->GetNumber() << s.top()->GetOperator();
	s.pop();
	cout << s.top()->GetNumber() << s.top()->GetOperator();
	s.pop();
}
