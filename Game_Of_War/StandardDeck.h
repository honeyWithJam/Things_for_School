// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#pragma once
#ifndef STANDARD_DECK_H		// #ifndef, #define, and #endif will be in every .h file for the rest of the class!
#define STANDARD_DECK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

#include "Deck.h"

//#include "card.h"

#define DECK_SIZE 52

/**
 * @class standardDeck
 *
 * The standardDeck class represents a standard deck of 52 cards.
 * 
 */
class standardDeck : public Deck
{
	public:
		int max_size = DECK_SIZE; 
		/// Default constructor.

		standardDeck(const standardDeck & other);

		Deck * clone() const override;
		
		standardDeck();
		
		/// Default destructor.
		~standardDeck();

		void initializeDeck();	// Ask Rybar about this one

		// bool mergeDecks(standardDeck & D, bool);	// same for both
		
};

#endif