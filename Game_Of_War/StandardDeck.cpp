// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "StandardDeck.h"


// standardDeck::standardDeck()
// {
    
// }

standardDeck::standardDeck() : Deck(DECK_SIZE)
{
    // if(numCards > 0)
    // {
    //     numCards_ = numCards;
    // }
    // else
    // {
    //     numCards_= 0;
    // }

    // if(numWins > 0)
    // {
    //     numWins_ = numWins;
    // }
    // else
    // {
    //     numWins_= 0;
    // }
}

standardDeck::standardDeck(const standardDeck & other) : Deck(other)
{
    std::cout << "Copying standardDeck..." << std::endl;
    
    for(int i = 0; i < numCards_; i++)
    {
        deck_[i] = other.deck_[i];

    } // copy the cards from the original deck into the new deck
}

Deck * standardDeck::clone() const
{
    return new standardDeck(*this);
}

standardDeck::~standardDeck()
{
    // if(deck_ != nullptr)
    // {
    //     delete [] deck_;
    // }

}

void standardDeck::initializeDeck()
{
    for(int suits = 1; suits < 5; suits++) 
    {
        for(int faces = 1; faces < 14; faces++)
        {
                Card newCard(suits, faces);
                addCard(newCard);
        }
    }
}




