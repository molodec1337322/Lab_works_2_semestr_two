#include <iostream>

using namespace std;

class SomeClass
{
    static int numberOfObjects;

private:
    int id;

public:
    SomeClass() : id(++numberOfObjects)
    {}

    int GetID() const
    {
        return id;
    }
};
int SomeClass::numberOfObjects = 0;

int main()
{
    setlocale(LC_ALL, "Russian");

    SomeClass classes[3];
    for (SomeClass currClass : classes)
    {
        cout << "Мой порядковый номер: " << currClass.GetID() << "\n";
    }
}
