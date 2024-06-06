//John Marshall Assignment 2

#pragma once
#ifndef Deck_H
#define Deck_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sorting.h"
#include "Card.h"

class Deck {
    public:
        //properties
        Card cards[52];

        //constructors
        Deck();

        //methods
        void printDeck();
        
        void shuffle();
        void sortByValueOnly();
        void sortByValueAndSuit();

};



    Deck::Deck(){
        int cardIndex = 0;
        Card tempDeck[52];


        for (int i = 1; i < 5; i++) { //start loop at one so suits can be assigned 
            for (int x = 2; x < 15; x++) {            //start loop at 2 because it is the lowest value of any card
                this->cards[cardIndex] = Card(i, x);
                cardIndex++;
            };
        };

    };

    //prints cards in Deck
     void Deck::printDeck() {
        for (int i = 0; i < 52; i++) {
            this->cards[i].printCard();
        };
     };


     //Fisher-Yates Shuffle Algorithm 
     void Deck::shuffle() {
         int shuffleCount = 52;

         for (int i = 0; i < shuffleCount; i++) {
             srand(time(NULL));
             int randNum = rand() % (shuffleCount - i);

             Card temp = this->cards[i];
             this->cards[i] = this->cards[randNum];
             this->cards[randNum] = temp;
         };
     };
     //sort using bubble sort Not by suit
     void Deck::sortByValueOnly() {
         mergesort(this->cards,0, 51);
     };

     void Deck::sortByValueAndSuit() {
        //temp stack for suits

        Card clubs[13];
        Card diamonds[13];
        Card hearts[13];
        Card spades[13];

        //keeps track of temp stack index
        int clubsCounter = 0;
        int diamondCounter = 0;
        int heartsCounter = 0;
        int spadesCounter = 0;

        quicksortSuit(this->cards,0,51);

        //put Cards into Temp Decks for Sorting
        for(int i = 0; i < 52; i++){
            switch (this->cards[i].suitRefNum)
            {
            case 1:
                clubs[clubsCounter] = this->cards[i];
                clubsCounter++;
                break;
            case 2:
                diamonds[diamondCounter] = this->cards[i];
                diamondCounter++;
                break;
            case 3:
                hearts[heartsCounter] = this->cards[i];
                heartsCounter++;
                break;
            case 4:
                spades[spadesCounter] = this->cards[i];
                spadesCounter++;
                break;
            default:
                break;
            };
        };

        //sort temp stacks by value
        quicksortValue(clubs,0,12);
        quicksortValue(diamonds,0,12);
        quicksortValue(hearts,0,12);
        quicksortValue(spades,0,12);

        //merge sorted stacks
        for(int x = 0; x < 52; x++){
            if(x == 0){
                this->cards[x] = clubs[x];
            } else if(x>0 && x<13){
                this->cards[x] = clubs[x];
            } else if(x>12 && x<26){
                this->cards[x] = diamonds[x-13];
            } else if(x>25 && x<39) {
                this->cards[x] = hearts[x-26];
            } else{
                this->cards[x] = spades[x-39];
            }
        };

     };

#endif
