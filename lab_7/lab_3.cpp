#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;


class String 
{
private:
	const static int STRING_SIZE = 50;
	char str[STRING_SIZE];

public:

	String()
	{
		strncpy(str, "", STRING_SIZE);
	}

	String(char s[]) 
	{
		strncpy(str, s, STRING_SIZE);
	}

	void display() const 
	{
		for (int i = 0; i < STRING_SIZE; i++)
		{
			cout << str[i];
		}
	}

	String operator += (String s2) const 
	{
		String temp; 

		if (strlen(str) + strlen(s2.str) < STRING_SIZE)
		{
			strncpy(temp.str, str, strlen(str));
			strncat(temp.str, s2.str, strlen(s2.str));
			temp.str[strlen(str) + strlen(s2.str) + 1] = '\0';
		}

		else
		{
			cout << "\nString overflow"; exit(1);
		}

		return temp; 
	}

	String operator + (String s2) const
	{
		String temp;

		if (strlen(str) + strlen(s2.str) < STRING_SIZE)
		{
			strncpy(temp.str, str, strlen(str));
			strncat(temp.str, s2.str, strlen(s2.str));
			temp.str[strlen(str) + strlen(s2.str) + 1] = '\0';
		}

		else
		{
			cout << "\nString overflow"; exit(1);
		}

		return temp;
	}
};



int main()
{
	char str_1[7] = {'M', 'e', 'r', 'r', 'r', 'y', '\0'};
	char str_2[11] = {' ', 'c', 'h', 'r', 'i', 's', 't', 'm', 'a', 's', '\0'};
	String s1(str_1); 
	String s2(str_2); 

	String s3;

	s3 = s1 += s2; 


	s3.display(); 

	cout << endl;

	return 0;
}

