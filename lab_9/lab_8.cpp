#include <iostream>

using namespace std;


struct link 
{
	int data; 
	link* next; 
};


class linklist 
{
private:
	link* first; 

public:
	linklist() 
	{
		first = NULL;
	} 
	void additem(int d); 
	void display(); 
};


void linklist::additem(int d) 
{
	link* newlink = new link;
	newlink->data = d;
	if (first)
	{
		link* current = first;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newlink;
	}
	else
	{
		first = newlink;
	}
	newlink->next = NULL;
}


void linklist::display() 
{
	int i = 0;
	link* current = first; 
	while (current != NULL) 
	{
		cout << current->data << endl; 
		current = current->next; 
	}
}


int main()
{
	linklist li; 

	li.additem(25); 
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display(); 

	return 0;
}
