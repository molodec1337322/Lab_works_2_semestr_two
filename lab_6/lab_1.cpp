#include <iostream>
#include <string>

using namespace std;

void reverseit(string &str)
{
	reverse(str.begin(), str.end());
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string str;

	cout << "Введите сстроку: ";
	getline(cin, str);
	reverseit(str);
	cout << str;
}
