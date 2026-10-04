// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{

}

Card::Card(int suitVal, int faceVal)
{
    suitVal_ = suitVal;
    faceVal_ = faceVal;
}

Card::~Card()
{

}

std::string Card::getSuit() 
{
    return SUIT[suitVal_];
}

int Card::getSuitVal()
{
    return suitVal_;
}

std::string Card::getFace()
{
    return FACE[faceVal_];
}

int Card::getFaceVal()
{
    return faceVal_;
}

std::string Card::print()
{
    return FACE[faceVal_] + " Of " + SUIT[suitVal_]; 
}

void Card::initialize(int, int)
{
    SUIT[suitVal_];
    FACE[faceVal_];

}