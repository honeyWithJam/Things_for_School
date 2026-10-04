A2.exe: DriverA2.o card.o StandardDeck.o Deck.o NonStandardDeck.o
	g++ DriverA2.o card.o StandardDeck.o Deck.o NonStandardDeck.o -o A2.exe 

DriverA2.o: DriverA2.cpp
	g++ -O2 -c  -g DriverA2.cpp -o DriverA2.o
	
card.o: card.cpp
	g++ -O2 -c  -g card.cpp -o card.o

StandardDeck.o: StandardDeck.cpp
	g++ -O2 -c  -g StandardDeck.cpp -o StandardDeck.o

Deck.o: Deck.cpp
	g++ -O2 -c  -g Deck.cpp -o Deck.o

NonStandardDeck.o: NonStandardDeck.cpp
	g++ -O2 -c  -g NonStandardDeck.cpp -o NonStandardDeck.o

clean:
	rm -rf *.o A2.exe

commit:

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.txt ./A2.exe


run:
	./A2.exe	