#include <iostream>

using namespace std;

class Queue
{
private:
	int head;
	int tail;

	const static int MAX = 500;
	int arr[MAX];

	void CheckState()
	{
		if (tail == MAX - 1)
		{
			tail = 0;
		}

		if (head == MAX - 1)
		{
			head = 0;
		}
	}

public:
	Queue(): head(0), tail(0)
	{}

	void Put(int val)
	{
		CheckState();
		arr[tail++] = val;
	}

	int Get()
	{
		CheckState();
		return arr[head++];
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	Queue q;
	q.Put(2); q.Put(7); q.Put(12);

	cout << "Значения очереди равны: ";
	cout << q.Get() << " ";
	cout << q.Get() << " ";
	cout << q.Get();
}
