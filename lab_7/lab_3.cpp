#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;


class String 
{
private:
	const static int STRING_SIZE = 250;
	char str[STRING_SIZE];

public:

	String()
	{
		strcpy(str, "");
	}

	String(char s[]) 
	{
		strcpy(str, s);
	}

	void display() const 
	{
		cout << str;
	}

	String operator += (String s2) const 
	{
		String temp; 

		if (strlen(str) + strlen(s2.str) < STRING_SIZE)
		{
			strcpy(temp.str, str); 
			strcat(temp.str, s2.str);
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
	char str_1[6] = {'M', 'e', 'r', 'r', 'r', 'y'};
	char str_2[10] = {' ', 'c', 'h', 'r', 'i', 's', 't', 'm', 'a', 's'};
	String s1(str_1); 
	String s2(str_2); 

	String s3;

	s1.display();
	s2.display();
	s3.display();

	s3 = s1 += s2; 

	s3.display(); 

	cout << endl;

	return 0;

}
