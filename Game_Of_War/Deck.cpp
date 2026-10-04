//Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "Deck.h"

Deck::Deck() : numCards_(0), size_(0), deck_(new Card[size_]), numWins_(0), sumCards_(0) // initialization list
{

}

Deck::Deck(int size) : numCards_(0), size_(size), deck_(new Card[size]), numWins_(0), sumCards_(0)// initialization list
{

}

// copy constructor for the Deck class
Deck::Deck(const Deck & other) : numCards_(other.numCards_), size_(other.size_), deck_(new Card[other.size_]), numWins_(other.numWins_), sumCards_(other.sumCards_)
{
    for(int i = 0; i < numCards_; i++)  // copy each card from the original deck, seems kind of redundant for this project, but keep it for future projects
    {
        deck_[i] = other.deck_[i];  // copy each card from original deck to copied deck

    } // copy the cards from the original deck into the new deck
} 

Deck::~Deck()   // destructor for Deck
{
    if(deck_ != nullptr)    // check if there is a null pointer 
    {
        delete [] deck_;    // if no null pointer, delete the deck
    }

}

bool Deck::addCard(Card c)  // add card to deck
{
    if(numCards_ < size_)   // check if there is space in the deck
    {   
        deck_[numCards_] = c;   // if there is, add the card to the deck
        numCards_++;   // increment the number of cards in the deck

        return true;    // then return
    }
    else
    {
        return false;   // return false if there is no space in the deck
    }
}

bool Deck::mergeDecks(Deck * D, bool b) // merge together the decks
{
    if(numCards_ < size_)   // check if there is space in the deck to merge
    {
        int mergeNum = size_ - numCards_;   // the max num you can put into current deck

        if(mergeNum > D -> getNumCards())  // check if second deck num is less than merge num
        {
            mergeNum = D -> getNumCards(); // if it does, make merge num equal to second deck num 
        }

        for(int i = 0; i < mergeNum; i++)   // run the merge
        {
            deck_[numCards_ + i] = D -> deck_[i];  // merge the next availiable place in first deck with next card of second deck
        }

        numCards_ += mergeNum; // correct the number of cards in the first deck

        if(mergeNum < D -> getNumCards())  // check if mergeNum is less than number of cards in  second deck
        {
            D -> setNumCards(D -> getNumCards() - mergeNum);  // if so, set num cards in second deck to its num cards minus mergeNum
        }
        else
        {
            D -> numCards_ = 0;    // else set the second deck to 0
        }

        if(b == true)   // check if b is true
        {
            randomShuffle();    // if it is, shuffle
        }

        return b; // then return true
    }

    return false;
}

void Deck::randomShuffle()  // credit: 
                            //https://documents.uow.edu.au/~lukes/textbook/notes-cpp/misc/random-shuffle.html
{
    std::srand(std::time(0)); // set seed based on the time

    for(int i = 0; i < numCards_; i++) // iterate through each card
    {
        int r = (rand() % numCards_); // make random index
        Card temp = deck_[i]; // make temp var, and swap with ith card
        deck_[i] = deck_[r]; // swap the ith card with the randomly chosen card
        deck_[r] = temp; // complete the swap

    }

}

bool Deck::isEmpty()    // check if the deck is empty
{
    if(numCards_ == 0) // if deck is empty
    {
        return true; // return true
    }
    else
    {
        return false; // return false
    }
}

void Deck::setNumCards(int num) // set the number of cards in deck, be careful using this
{
    numCards_ = num; 
}

Card Deck::dealCard()   // deal out  the cards for the players
{
    numCards_--;    // decrease number of cards by one
    return deck_[numCards_];    // return the card that is dealt
}

int Deck::getNumCards() // returns the number of cards in the deck
{
    
    return numCards_;  
}

int Deck::getNumWins()  // returns the number of wins for the deck
{
    return numWins_;
}

void Deck::deckWins()
{
    numWins_++;
}

void Deck::displayCard(int i)   // prints the ith card
{

    std::cout << deck_[i].print() << std::endl; // display the ith card
     
}

bool Deck::compare(Deck * Cards)   // compare the top card of this deck to the top card of another deck
{
    if(getTopCard() == Cards->getTopCard()) // if the top cards are equal
    {
        return true; // return true
    }
    else
    {
        return false; // return false
    }

}

std::string Deck::getTopCard() // return the face of the top card
{
    return deck_[numCards_ - 1].getFace(); // return the face
}

int Deck::getSuitVal(int i) // return suit val of ith card
{
    int suitVal = deck_[i].getSuitVal(); // get suit val of ith card
    
    return suitVal; // then return it

}
    
int Deck::getFaceVal(int i) // return face val of ith card
{
    int faceVal = deck_[i].getFaceVal(); // get face val of ith card

    return faceVal; // then return it
}

void Deck::sumCards()  // add the current number of cards to the sum of cards
{
    sumCards_ = sumCards_ + numCards_;
}

int Deck::getAverageCards()
{
    int averageWins = sumCards_ / TOTALGAMES; // calculate the average number of cards

    return averageWins; // return the average
}



void Deck::printDeck()  // prints the whole deck
{
    for(int i = 0; i < numCards_; i++)
    {
        displayCard(i);
    }
}


