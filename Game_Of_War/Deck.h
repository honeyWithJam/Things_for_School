// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#pragma once
#ifndef DECK_H		// #ifndef, #define, and #endif will be in every .h file for the rest of the class!
#define DECK_H

#define TOTALGAMES 50

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iterator>

#include "card.h"

/*
    @class Deck

    The Deck class represents an abstract deck of cards

*/

class Deck
{
	public:

		/// Default constructor.
		Deck();
		
		Deck (int size);

		Deck(const Deck & other);

		virtual Deck * clone() const = 0;	// https://iamsorush.com/posts/cpp-polymorphic-clone/

		/// Default destructor.
		virtual ~Deck(); 

		void randomShuffle(); // same for both

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	// same for both 

		void setNumCards(int num);	// same for both

		bool addCard(Card C);	// same for both

		Card dealCard();    // same for both

		virtual void initializeDeck() = 0;
		/*
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 

		bool mergeDecks(Deck * D, bool b);

		int getNumCards();	// same for both

		void displayCard(int i);	// same for both

		bool compare(Deck * Cards);

		std::string getTopCard();	// same for both

		int getSuitVal(int i);

		int getFaceVal(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// stores the number of Cards currently in the deck.
		int size_;	// used for non-standard deck
};

#endif