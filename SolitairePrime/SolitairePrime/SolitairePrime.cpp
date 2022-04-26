// SolitairePrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Samuel Garcia
// CECS 282-07
// Prog 1 - Solitaire Prime
// 2/12/2020

#include "Card.h"
#include "Deck.h"
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    // Corner case 
    if (n <= 1)
    {
        return false;
    }

    // Check from 2 to n-1 
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void displayMenu()
{
    cout << "Welcome to Solitaire Prime!\n";
    cout << "1) New Deck\n";
    cout << "2) Display Deck\n";
    cout << "3) Shuffle Deck\n";
    cout << "4) Play Solitaire Prime\n";
    cout << "5) Exit\n\n";
}

int main()
{
    Deck gameDeck;
    int choice;
    bool flag = true;

    while (flag)
    {
        displayMenu();
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // create new deck
            gameDeck.refreshDeck();
            cout << "Standard deck is created.\n" << endl;
            break;
        }
        case 2:
        {
            // display deck
            gameDeck.showDeck();
            cout << "\n" << endl;
            break;
        }
        case 3:
        {
            // shuffle deck
            gameDeck.shuffle();
            cout << "Deck is shuffled.\n" << endl;
            break;
        }
        case 4:
        {
            // breaks if there are 0 cards left
            if (gameDeck.cardsLeft() == 0)
            {
                cout << "There are " << gameDeck.cardsLeft() << " cards left." << endl;
                cout << "You must create a new deck to play again.\n" << endl;
                break;
            }

            // play the game
            cout << "Playing Solitaire Prime!!!\n" << endl;
            int pileSum = 0;
            int pileCounter = 0;

            // while there are cards to deal
            while (gameDeck.cardsLeft() != 0)
            {
                // while the sum of pile is not prime and there are still cards to deal
                while (!isPrime(pileSum) && gameDeck.cardsLeft() != 0)
                {
                    Card card = gameDeck.deal();
                    card.showCard();
                    pileSum += card.getValue();
                }
                pileCounter++;

                if (isPrime(pileSum))
                {
                    cout << "Prime: " << pileSum << endl;
                    if (gameDeck.cardsLeft() == 0)
                    {
                        cout << "\nWinner in " << pileCounter << " piles!\n" << endl;
                    }
                }
                if (!isPrime(pileSum) && gameDeck.cardsLeft() == 0)
                {
                    cout << "You lose.\n" << endl;
                }
                pileSum = 0;
            }
            break;
        }
        case 5:
        {
            // ends the program
            cout << "End of program." << endl;
            flag = false;
            break;
        }
        }
    }
    return 0;
}