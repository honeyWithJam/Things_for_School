// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

#include "StandardDeck.h"
#include "NonStandardDeck.h"

void dealCards(Deck * battleGround, Deck * Deck1, Deck * Deck2) // dealcards could be the potential problem for all the errors
{

    while (!(battleGround -> isEmpty())) // deal out the cards to each player
    {

        Deck1 -> addCard(battleGround -> dealCard()); // player one gets a card

        // if(!battleGround -> isEmpty()) // recheck to see if BG is empty, just in case num cards is odd
        // {
        //     Deck2 -> addCard(battleGround -> dealCard()); // player two gets a card
        // }
        Deck2 -> addCard(battleGround -> dealCard());

    } 

}

void makeCards(Deck * b)    // makes cards for nonstandard Deck
{
    std::ofstream out;

    out.open("Deck.txt", std::ofstream::trunc);

    int nonStanCards = b -> getNumCards() * 50;
    out << nonStanCards << std::endl;
    //int nonStanCards = b.getNumCards() * TOTALGAMES

    for(int i = 0; i < nonStanCards; i++)
    {
        if(i < 52)
        {
            out << b -> getSuitVal(i) << " " << b -> getFaceVal(i) << std::endl;
        }
        else
        {
            out << b -> getSuitVal(i % 52) << " " << b -> getFaceVal(i % 52) << std::endl;
        }
    }

    out.close();
}

int gameOfWar(Deck * battleGround, Deck * Deck1, Deck * Deck2)
{   

    int numGames = 0;

    for(int i = 0; i < DECK_SIZE; i++)
    {
        battleGround -> randomShuffle();
    }

    while(numGames < TOTALGAMES)
    {
        
        //std::this_thread::sleep_for(std::chrono::seconds(.05));

        for(int i = 0; i < DECK_SIZE; i++)  // shuffle the deck 52 times
        {
            battleGround -> randomShuffle();
        }

        dealCards(battleGround, Deck1, Deck2);  // deal out the cards to each player

        while((!Deck1 -> isEmpty()) && (!Deck2 -> isEmpty())) // game of war
        {

            if((!battleGround -> isEmpty()) && (battleGround -> compare(Deck1))) // check if the BG is empty and BG top card and D1 top card are same
            {
                Deck1 -> mergeDecks(battleGround, true);  // if true, merge BG into D1
                battleGround -> addCard(Deck1 -> dealCard()); // and have D1 put card into BG
            }   
            else    // if false
            {
                battleGround -> addCard(Deck1 -> dealCard());   // player one puts card in battleground
            }

            if((!battleGround -> isEmpty()) && (battleGround -> compare(Deck2)))    // check if BG is empty and BG top card and D2 top card are same
            {   
                Deck2 -> mergeDecks(battleGround, true);   // player two merges battleground into their deck
                battleGround -> addCard(Deck2 -> dealCard());  // and have player 2 put a card in the battleground
            }
            else
            {
                battleGround -> addCard(Deck2 -> dealCard());   // player two puts card in battleground
            }
                  
        }

        if(Deck2 -> isEmpty()) // check if player two has no cards left
        {
            Deck1 -> deckWins(); // if so, add a card to player ones win count
            Deck1 -> sumCards(); // update player ones total card count
        }
        else // if player one has no cards left (Deck1 -> isEmpty)
        {
            Deck2 -> deckWins(); // if so, add a card to player twos win count
            Deck2 -> sumCards(); // update player twos total card count
        }

        battleGround -> mergeDecks(Deck1, false);   // merge deck 1 into BG
        battleGround -> mergeDecks(Deck2, false);   // merge deck 2 into BG

        numGames++; // increase the number of games played
    }

    return numGames;    // return the number of games played
}

int main()
{ 

    // create the players, and battlegrounds as deck objects

    Deck * Deck1 = new standardDeck;    // player 1 - standard
    // Deck * Deck2 = new standardDeck;   // player 2- standard
    
    // Deck Deck2 = *Deck1;

    Deck * Deck2 = Deck1 -> clone();

    // Deck Deck2 = new standardDeck(*Deck1);

    Deck * Deck3 = new nonStandardDeck; // player 1 - nonstandard
    // Deck * Deck4 = new nonStandardDeck; // player 2- nonstandard

    // Deck * Deck4(Deck3);

    Deck * Deck4 = Deck3 -> clone();

    Deck * battleGround = new standardDeck; // battleground - standard
    // Deck * battleGround2 = new nonStandardDeck ; // battleground - nonstandard

    // Deck * battleGround2(battleGround);

    Deck * battleGround2 = Deck3 -> clone();

    // create the deck array

    Deck * deckArray[6];

    // place all the players inside of the deck array

    deckArray[0] = Deck1;
    // deckArray[1] = Deck2;

    deckArray[1] = Deck2;

    deckArray[2] = Deck3;
    // deckArray[3] = Deck4;

    deckArray[3] = Deck4;

    deckArray[4] = battleGround;
    // deckArray[5] = battleGround2;
    
    deckArray[5] = battleGround2;
    
    // initialize the standard battleground using standard init deck

    deckArray[4] -> initializeDeck();

    // play the first game of war

    int numGames = gameOfWar(deckArray[4], deckArray[0], deckArray[1]);

    // create the cards for the second deck from the first deck
    // this prints the cards from the first deck into "Deck.txt"

    makeCards(deckArray[4]);

    // initialize the non standard deck using non standard init deck

    deckArray[5] -> initializeDeck();

    int numGames2 = gameOfWar(deckArray[5], deckArray[2], deckArray[3]);    // play the non standard deck of war

    // print winners

    if(deckArray[0] -> getNumWins() > deckArray[1] -> getNumWins()) // player 1 wins
    {
        std::cout << "Player 1 was the champion with " << deckArray[0] -> getNumWins() << " vitories versus Player 2" << std::endl;
    }
    else if(deckArray[0] -> getNumWins() < deckArray[1] -> getNumWins()) // player 2 wins
    {
        std::cout << "Player 2 was the champion with " << deckArray[1] -> getNumWins() << " vitories versus Player 1" << std::endl;
    }
    else // tie
    {
        std::cout << "The players tied with " << deckArray[0] -> getNumWins() << " victories." << std::endl;
    }

    std::cout << "" << std::endl;

    std::cout << "Player 1 Average Score: " <<  deckArray[0] -> getAverageCards() << std::endl;
    std::cout << "Player 2 Average Score: " <<  deckArray[1] -> getAverageCards() << std::endl;

    std::cout << "" << std::endl;

    std::cout << "NonStandardDeck Game: " << std::endl;

    std::cout << "" << std::endl;

    if(deckArray[2] -> getNumWins() > deckArray[3] -> getNumWins()) // player 1 wins
    {
        std::cout << "Player 1 was the champion with " << deckArray[2] -> getNumWins() << " vitories versus Player 2" << std::endl;
    }
    else if(deckArray[2] -> getNumWins() < deckArray[3] -> getNumWins()) // player 2 wins
    {
        std::cout << "Player 2 was the champion with " << deckArray[3] -> getNumWins() << " vitories versus Player 1" << std::endl;
    }
    else // tie
    {
        std::cout << "The players tied with " << deckArray[2] -> getNumWins() << " victories." << std::endl;
    }

    std::cout << "Player 1 Average Score: " <<  deckArray[2] -> getAverageCards() << std::endl;
    std::cout << "Player 2 Average Score: " <<  deckArray[3] -> getAverageCards() << std::endl;


    for(int i = 0; i < std::size(deckArray); i++)   // delete all decks
    {
        delete deckArray[i];    // delete the ith deck
    }

}
