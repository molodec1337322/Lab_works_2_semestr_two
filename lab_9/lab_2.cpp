#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include <cctype> 
#include "ctype.h"

using namespace std;

class String 
{
private:
	char* str; 
public:

	String(char* s)
	{
		int length = strlen(s); 
		str = new char[length + 1]; 
		strcpy(str, s); 
	}

	~String() //destructor
	{
		delete str;
	}

	void display() 
	{
		cout << str;
	}

	void upit(); 
};


void String::upit() 
{
	char* ptrch = str; 
	while (*ptrch) 
	{
		*ptrch = toupper(*ptrch); 
		ptrch++; 
	}
}


int main()
{
	char str[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
	String s1(str);

	cout << "\ns1="; 
	s1.display();

	s1.upit(); 

	cout << "\ns1="; 
	s1.display();

	cout << endl;
	return 0;
}
