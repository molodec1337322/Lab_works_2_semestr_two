#include <iostream>

using namespace std;

class Int
{
private:
    int i;

public:
    Int()
    {
        i = 0;
    }

    Int(int num)
    {
        i = num;
    }

    void add(Int i_2, Int i_3)
    {
        i = i_2.i + i_3.i;
    }

    void display()
    {
        cout << i;
    }
};

int main()
{
    Int int_1(7);
    Int int_2(11);
    Int int_3;

    int_3.add(int_1, int_2);

    cout << "\nInt3 = ";
    int_3.display();
    cout << endl;
}
