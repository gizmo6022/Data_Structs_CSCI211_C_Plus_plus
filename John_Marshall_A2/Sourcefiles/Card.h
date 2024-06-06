//John Marshall Assignemnt 2


#pragma once
#ifndef Card_H
#define Card_H
#include <string>
#include <iostream>
using std::string;


class Card {       // Card Class
public:

    int valRefNum;    //Ref number used for sorting
    int suitRefNum;   //Ref number to determine the suit
    string value;     // value of the card as seen on face
    string suit;      //Suit of card as a string


    //Constructors
    Card();
    Card(int suitRefNum, int valRefNum);

    void printCard();

};

Card::Card() {
    this->valRefNum = 0;
    this->suitRefNum = 0;
    this->value = "";
    this->suit = "";
};

//Constructor
Card::Card(int suitRefNum, int valRefNum) {
    this->valRefNum = valRefNum;
    this->suitRefNum = suitRefNum;



    switch (valRefNum) { //Switch to assign values of the cards
    case 11:
        this->value = "J";
        break;
    case 12:
        this->value = "Q";
        break;
    case 13:
        this->value = "K";
        break;
    case 14:
        this->value = "A";
        break;
    default:
        this->value = std::to_string(valRefNum);
    };

    switch (suitRefNum) { //Switch to assign suits to cards as they are created
    case 1:
        this->suit = "C";
        break;
    case 2:
        this->suit = "D";
        break;
    case 3:
        this->suit = "H";
        break;
    case 4:
        this->suit = "S";
        break;
    };



};//end Constructor

void Card::printCard() {
    std::cout << this->value << " - " << this->suit << "\n";
};

#endif
