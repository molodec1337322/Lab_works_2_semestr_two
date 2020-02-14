#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

enum etype { laborer, secretary, manager,
             accountant, executive, researcher };

int main()
{
    char workerType;
    etype type;
    cout << "Введите первую букву должности: ";
    cin >> workerType;
    
    switch(workerType)
    {
      case 'l':
        type = laborer;
        break;
      case 's':
        type = secretary;
        break;
      case 'm':
        type = manager;
        break;
      case 'a':
        type = accountant;
        break;
      case 'e':
        type = executive;
        break;
      case 'r':
        type = researcher;
    }
    
    string employeeType;
    switch(type)
    {
      case laborer:
        employeeType = "laborer";
        break;
      case secretary:
        employeeType = "secretary";
        break;
      case manager:
        employeeType = "manager";
        break;
      case accountant:
        employeeType = "accountant";
        break;
      case executive:
        employeeType = "executive";
        break;
      case researcher:
        employeeType = "researcher";
        break;
    }
    
    cout << "Вы выбрали " << employeeType;
}
