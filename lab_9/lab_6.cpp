#include <iostream>

using namespace std;

int Compstr(char* str1, char* str2)
{
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if ((short)str1[i] < (short)str2[i])
		{
			return -1;
		}
		else if ((short)str1[i] > (short)str2[i])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str1[6] = { 'a', 'a', 'b', 'b', 'c', '\0' };
	char str2[6] = { 'a', 'a', 'b', 'b', 'c', '\0' };

	cout << Compstr(str1, str2);

	return 0;
}
