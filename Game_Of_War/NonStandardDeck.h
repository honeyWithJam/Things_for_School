// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#pragma once
#ifndef NON_STANDARD_DECK_H		// #ifndef, #define, and #endif will be in every .h file for the rest of the class!
#define NON_STANDARD_DECK_H

#define SIZE 2600

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
		nonStandardDeck();

		nonStandardDeck(const nonStandardDeck & other);

		Deck * clone() const override;
		
		~nonStandardDeck();

		void initializeDeck();

		//bool mergeDecks(nonStandardDeck & D, bool b);


};

#endif