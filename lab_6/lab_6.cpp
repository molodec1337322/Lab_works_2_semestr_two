#include <iostream>
#include <cstdlib> 
#include <ctime>


using namespace std;

enum Suit 
{
	clubs, diamonds, hearts, spades
};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card 
{
private:
	int number;
	Suit suit;

public:
	Card()
	{}

	void set(int number, Suit suit) 
	{
		this->number = number;
		this->suit = suit;
	}

	void Display()
	{
		if (number >= 2 && number <= 10)
		{
			cout << number;
		}
		else
		{
			switch (number)
			{
			case jack:
				cout << "J";
				break;

			case queen:
				cout << "Q";
				break;

			case king:
				cout << "K";
				break;

			case ace:
				cout << "A";
				break;
			}
		}

		switch (suit)
		{
		case clubs:
			cout << "♣";
			break;

		case diamonds:
			cout << "♦";
			break;

		case hearts:
			cout << "♥";
			break;

		case spades:
			cout << "♠";
			break;
		}
	}
};



int main()
{
	Card deck[52];
	for (int i = 0; i < 52; i++) 
	{
		int number = (i % 13) + 2; 
		Suit suit = Suit(i / 13); 
		deck[i].set(number, suit);
	}

	cout << "-------\n";

	for (int i = 0; i < 52; i++) 
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13)) cout << endl; 
	}

	srand(time(NULL));

	for (int i = 0; i < 52; i++) 
	{
		int k = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[k];
		deck[k] = temp;
	}
	cout << "\n--------------\n";

	for (int i = 0; i < 52; i++) 
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13)) cout << endl; 
	}

}
