#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> //for strcpy(), etc
#include <cctype> //for toupper()
#include "ctype.h"

using namespace std;

class String //user-defined string type
{
private:
	char* str; //pointer to string

public:

	String(char* s) //constructor, one arg
	{
		int length = strlen(s); //length of string argument
		str = new char[length + 1]; //get memory
		strcpy(str, s); //copy argument to it
	}

	~String() //destructor
	{
		delete str;
	}

	void display() //display the String
	{
		cout << str;
	}

	void upit(); //uppercase the String
};


void String::upit() //uppercase each character
{
	char* ptrch = str; //pointer to this string
	while (*ptrch) //until null,
	{
		*ptrch = toupper(*ptrch); //uppercase each character
		ptrch++; //move to next character
	}
}


int main()
{
	char str[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
	String s1(str);

	cout << "\ns1="; //display string
	s1.display();

	s1.upit(); //uppercase string

	cout << "\ns1="; //display string
	s1.display();

	cout << endl;
	return 0;
}
