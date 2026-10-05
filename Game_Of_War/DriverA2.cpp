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

int gameOfWar(Deck * battleGround, Deck * Deck1, Deck * Deck2, int gameResults[])
{   

    int numGames = 0;
    int totalWinsD1 = 0;
    int totalWinsD2 = 0;
    int totalCardsD1 = 0;
    int totalCardsD2 = 0;

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
            totalWinsD1++; // if so, add a card to player ones win count
            totalCardsD1 = totalCardsD1 + Deck1 -> getNumCards(); // update player ones total card count

        }
        else // if player one has no cards left (Deck1 -> isEmpty)
        {
            totalWinsD2++; // if so, add a card to player twos win count
            totalCardsD2 = totalCardsD2 + Deck2 -> getNumCards(); // update player twos total card count
        }

        battleGround -> mergeDecks(Deck1, false);   // merge deck 1 into BG
        battleGround -> mergeDecks(Deck2, false);   // merge deck 2 into BG

        numGames++; // increase the number of games played
    }

    gameResults[0] = numGames;  // index the numGames in 0 
    gameResults[1] = totalWinsD1; // index the total wins of player 1 in 1
    gameResults[2] = totalWinsD2; // index the total wins of player 2 in 2
    gameResults[3] = totalCardsD1; // index the total cards of player 1 in 3
    gameResults[4] = totalCardsD2; // index the total cards of player 2 in 4

    return 0;
}

int avgCards(int totalCards)
{
    return totalCards / TOTALGAMES; // calculate the avg num of cards per player
}

void printGameResults(int gameResults[5])
{
    int numGames = gameResults[0]; // get the number of games played
    int totalWinsD1 = gameResults[1]; // get the total wins of player 1
    int totalWinsD2 = gameResults[2]; // get the total wins of player 2
    int totalCardsD1 = gameResults[3]; // get the total cards of player 1
    int totalCardsD2 = gameResults[4]; // get the total cards of player 2

    if(totalWinsD1 > totalWinsD2) // player 1 wins
    {
        std::cout << "Player 1 was the champion with " << totalWinsD1 << " vitories versus Player 2" << std::endl;
    }
    else if(totalWinsD1 < totalWinsD2) // player 2 wins
    {
        std::cout << "Player 2 was the champion with " << totalWinsD2 << " vitories versus Player 1" << std::endl;
    }
    else // tie
    {
        std::cout << "The players tied with " << totalWinsD1 << " victories." << std::endl;
    }

    std::cout << "Player 1 Average Score: " <<  avgCards(totalCardsD1) << std::endl;    // p1 avg cards
    std::cout << "Player 2 Average Score: " <<  avgCards(totalCardsD2) << std::endl;    // p2 avg cards

}

int main()
{ 
    // create the players, and battlegrounds as deck objects

    Deck * Deck1 = new standardDeck;    // player 1 - standard
    // Deck * Deck2 = new standardDeck;   // player 2- standard

    Deck * Deck2 = Deck1 -> clone();

    // Deck Deck2 = new standardDeck(*Deck1);

    Deck * Deck3 = new nonStandardDeck; // player 1 - nonstandard
    // Deck * Deck4 = new nonStandardDeck; // player 2- nonstandard

    Deck * Deck4 = Deck3 -> clone();

    //Deck * battleGround = new standardDeck; // battleground - standard
    // Deck * battleGround2 = new nonStandardDeck ; // battleground - nonstandard

    Deck * battleGround = Deck1 -> clone();

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

    // and get the results of the first game

    int gameResults[5]; // make an array to put game results in

    gameOfWar(deckArray[4], deckArray[0], deckArray[1], gameResults);    // play the first game of war

    // create the cards for the second deck from the first deck
    // this prints the cards from the first deck into "Deck.txt"

    makeCards(deckArray[4]);

    // initialize the non standard deck using non standard init deck

    deckArray[5] -> initializeDeck();

    // play the second game of war using non standard deck

    // and get the results of the second game

    int gameResults2[5];

    gameOfWar(deckArray[5], deckArray[2], deckArray[3], gameResults2);    // play the non standard deck of war

    // print winners

    std::cout << "StandardDeck Game: \n" << std::endl;

    printGameResults(gameResults);

    std::cout << "NonStandardDeck Game: \n" << std::endl;

    printGameResults(gameResults2);

    for(int i = 0; i < std::size(deckArray); i++)   // delete all decks
    {
        delete deckArray[i];    // delete the ith deck
    }

}
