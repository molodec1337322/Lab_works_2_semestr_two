//lab 1
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int width = 10;
    const int height = 20;

    int userNum;
    cout << "Введите число: ";
    cin >> userNum;

    for (int i = 0; i < width * height; i++)
    {
        if (i % width == 0)
        {
            cout << "\n";
        }
        cout << setw(6) << userNum * i;  
    }
}
