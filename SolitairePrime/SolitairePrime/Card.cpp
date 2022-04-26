#include <iostream>
#include "Card.h"
using namespace std;

Card::Card()
{
	rank = 'z';
	suit = 'z';
}
Card::Card(char r, char s)
{
	rank = r;
	suit = s;
}
void Card::setCard(char r, char s)
{
	rank = r;
	suit = s;
}
int Card::getValue()
{
	if (rank == 'A')
	{
		return 1;
	}
	if (rank == '2')
	{
		return 2;
	}
	if (rank == '3')
	{
		return 3;
	}
	if (rank == '4')
	{
		return 4;
	}
	if (rank == '5')
	{
		return 5;
	}
	if (rank == '6')
	{
		return 6;
	}
	if (rank == '7')
	{
		return 7;
	}
	if (rank == '8')
	{
		return 8;
	}
	if (rank == '9')
	{
		return 9;
	}
	if (rank == 'T' || rank == 'Q' || rank == 'J' || rank == 'K')
	{
		return 10;
	}
}
void Card::showCard()
{
	if (rank == 'T')
	{
		cout << "10" << suit << ", ";
	}
	else
	{
		cout << rank << suit << ", ";
	}
}

