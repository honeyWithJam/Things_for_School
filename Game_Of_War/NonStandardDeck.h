// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#pragma once
#ifndef NON_STANDARD_DECK_H		// #ifndef, #define, and #endif will be in every .h file for the rest of the class!
#define NON_STANDARD_DECK_H

#define SIZE 2600	// max size of nonstandard deck

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

class nonStandardDeck : public Deck
{
	public:
		nonStandardDeck(); // default construcor

		// nonStandardDeck(int size); // non-default constructor

		nonStandardDeck(const nonStandardDeck & other); // copy constructor

		Deck * clone() const override;	// clone the current nonStandard object
		
		~nonStandardDeck(); // default destructor

		void initializeDeck(); // initialize the cards found in Deck.txt

};

#endif