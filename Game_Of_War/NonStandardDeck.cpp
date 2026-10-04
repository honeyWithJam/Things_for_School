// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "NonStandardDeck.h"

nonStandardDeck::nonStandardDeck() : Deck(SIZE)
{
    std::ifstream Deckfile;
    
    Deckfile.open("Deck.txt");

    Deckfile >> size_;

    Deckfile.close();
}

nonStandardDeck::nonStandardDeck(const nonStandardDeck & other) : Deck(other)
{
    std::cout << "Copying nonStandardDeck..." << std::endl;
    
    for(int i = 0; i < numCards_; i++)
    {
        deck_[i] = other.deck_[i];

    } // copy the cards from the original deck into the new deck

}

Deck * nonStandardDeck::clone() const
{
    return new nonStandardDeck(*this);
}

nonStandardDeck::~nonStandardDeck()
{
    // if(deck_ != nullptr)
    // {
    //     delete [] deck_;
    // }
}

void nonStandardDeck::initializeDeck()	// will initialize the cards found in Deck.txt
{
    std::ifstream Deckfile;
    
    Deckfile.open("Deck.txt");

    Deckfile >> size_;

    int suit = 0;
    int face = 0;

    while(!(Deckfile.eof()))
    {
        Deckfile >> suit >> face;
        Card newCard(suit,face);
        addCard(newCard);
    }

    Deckfile.close();
    
    // while(numCards_ < size_)
    // {
    //     for(int suits = 1; suits < 5; suits++) 
    //     {
    //         for(int faces = 1; faces < 14; faces++)
    //         {
    //             if((numCards_ + 1) != size_)
    //             {
    //                 Card newCard(suits, faces);
    //                 addCard(newCard);
    //             }
    //         }
    //     }
    // }
}


// bool nonStandardDeck::mergeDecks(nonStandardDeck & D, bool b)
// {
//     if(numCards_ < size_)
//     {
//         int mergeNum = size_ - numCards_;   // the max num you can put into current deck

//         if(mergeNum > D.getNumCards())  // check if second deck num is less than merge num
//         {
//             mergeNum = D.getNumCards(); // if it does, make merge num equal to second deck num 
//         }

//         for(int i = 0; i < mergeNum; i++)   // run the merge
//         {
//             deck_[numCards_ + i] = D.deck_[i];  // merge the next availiable place in first deck with next card of second deck
//         }

//         numCards_ += mergeNum; // correct the number of cards in the first deck

//         if(mergeNum < D.getNumCards())  // check if mergeNum is less than number of cards in  second deck
//         {
//             D.setNumCards(D.getNumCards() - mergeNum);  // if so, set num cards in second deck to its num cards minus mergeNum
//         }
//         else
//         {
//             D.numCards_ = 0;    // else set the second deck to 0
//         }


//         if(b)   // check if b is true
//         {
//             randomShuffle();    // if it is, shuffle
//         }

//         return true; // then return true
//     }
//     else    // if the number of cards in first deck is not less than the number of cards that can fit in it
//     {
//         return false;   // you can't merge anything, so return back to driver
//     }
// }


