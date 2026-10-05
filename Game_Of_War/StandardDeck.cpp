// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "StandardDeck.h"

standardDeck::standardDeck() : Deck(DECK_SIZE) // default constructor
{
    if(size_ > 0) // if size is greater than 0
    {
        size_ = size_; // set number of cards to the size of the deck
    }
    else
    {
        size_ = 0; // else set the number of cards to 0
    }
}

standardDeck::standardDeck(const standardDeck & other) : Deck(other) // copy constructor
{
    for(int i = 0; i < numCards_; i++) // iterate through the deck
    {
        deck_[i] = other.deck_[i]; // copy each card

    } // copy the cards from the original deck into the new deck
}

Deck * standardDeck::clone() const
{
    return new standardDeck(*this); // creates a new copy of the current standardDeck object
}

standardDeck::~standardDeck() // default destructor
{
    // if(deck_ != nullptr)
    // {
    //     delete [] deck_;
    // }

}

void standardDeck::initializeDeck() // initialize the standard deck
{
    for(int suits = 1; suits < 5; suits++) // iterate through suits
    {
        for(int faces = 1; faces < 14; faces++) // iterate through faces
        {
                Card newCard(suits, faces); // create a new card with the current suit and face
                addCard(newCard); // add the card to the deck
        }
    }
}




