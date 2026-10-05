// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "NonStandardDeck.h"

// nonStandardDeck::nonStandardDeck()  // default constructor
// {

// }

nonStandardDeck::nonStandardDeck() : Deck(SIZE) // default constructor that initializes the deck size from Deck.txt
{
    std::ifstream Deckfile; // create Deckfile from ifstream
    
    Deckfile.open("Deck.txt");  // read in from Deck.txt

    Deckfile >> size_; // read in the size of the deck  

    if(size_ > 0) // check if the deck size is greater than 0
    {
        size_= size_;  // if so, set the number of cards to the deck size
    }
    else
    {
        size_ = 0; // else set it to 0 
    }

    Deckfile.close(); // close Deck.txt
}

nonStandardDeck::nonStandardDeck(const nonStandardDeck & other) : Deck(other)   // copy constructor
{

    for(int i = 0; i < numCards_; i++)  // iterate through the cards in the deck 
    {
        deck_[i] = other.deck_[i];  // copy each card

    } // copy the cards from the original deck into the new deck

}

Deck * nonStandardDeck::clone() const
{
    return new nonStandardDeck(*this); // creates a new copy of the current nonStandardDeck object
}

nonStandardDeck::~nonStandardDeck() // destructor 
{
    // if(deck_ != nullptr)
    // {
    //     delete [] deck_;
    // }
}

void nonStandardDeck::initializeDeck()	// will initialize the cards found in Deck.txt
{
    std::ifstream Deckfile; // create Deckfile from ifstream
    
    Deckfile.open("Deck.txt"); // read in from Deck.txt

    Deckfile >> size_; // read in the size of the deck

    int suit = 0;
    int face = 0;

    while(!(Deckfile.eof()))  // continue until the end of the file is reached
    {
        Deckfile >> suit >> face;  // read in the suit and face value of the next card
        Card newCard(suit,face);  // create a new card with the read values
        addCard(newCard);  // add the new card to the deck
    }

    Deckfile.close(); // close Deck.txt
}