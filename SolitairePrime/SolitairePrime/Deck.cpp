#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include "Deck.h"
#include "Card.h"
#include <time.h>
using namespace std;

Deck::Deck()
{
	top = 0;
	char suits[4] = { 'S','H','D','C' };
	char ranks[13] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	int index = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			storage[index].setCard(ranks[j], suits[i]);
			index++;
		}
	}
}
void Deck::refreshDeck()
{
	top = 0;
	char suits[4] = { 'S','H','D','C' };
	char ranks[13] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	int index = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			storage[index].setCard(ranks[j], suits[i]);
			index++;
		}
	}
}
Card Deck::deal()
{
	return storage[top++];
}
void Deck::shuffle()
{
	int times = 100;

	// swap x and y
	for (int i = 0; i < times; i++)
	{
		int x = rand() % 52;
		int y = rand() % 52;

		Card temp = storage[x];
		storage[x] = storage[y];
		storage[y] = temp;
	}

}
int Deck::cardsLeft()
{
	return 52 - top;
}

void Deck::showDeck()
{
	int counter = 0;
	for (int i = 0; i < 52; i++)
	{
		if (counter == 13)
		{
			cout << "\n";
			counter = 0;
		}
		storage[i].showCard();
		counter++;
	}
}