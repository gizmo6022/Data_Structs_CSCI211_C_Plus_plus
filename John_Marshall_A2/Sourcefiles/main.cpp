//John Marshall Assignment 2


//main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string> 
#include "Deck.h"
#include "Card.h"

using std::cout;

int main()
{
    Card card = Card();
    Deck deck = Deck();
    std::cout << "PRINT FRESH DECK -----------------------------------------------\n";
    deck.printDeck();

    std::cout << "SHUFFLE DECK -----------------------------------------------\n";
    deck.shuffle();
    deck.printDeck();

    std::cout << "SORT BY VALUE -----------------------------------------------\n";
    //sort without suit sorting
    deck.sortByValueOnly();
    deck.printDeck();

    std::cout << "SHUFFLE DECK -----------------------------------------------\n";
    deck.shuffle();
    deck.printDeck();

    std::cout << "SORT BY VALUE AND SUIT-----------------------------------------------\n";
    //sort with suit sorting
    deck.sortByValueAndSuit();
    deck.printDeck();
};
