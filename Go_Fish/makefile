CC=g++ -std=c++11
exe=prog

$(exe): card.o deck.o hand.o player.o game.o main.cpp 
	$(CC) card.o deck.o hand.o player.o game.o main.cpp -o $(exe)

card.o: card.cpp card.h
	$(CC) -c card.cpp

deck.o: deck.cpp deck.h
	$(CC) -c deck.cpp

hand.o: hand.cpp hand.h
	$(CC) -c hand.cpp

player.o: player.cpp player.h
	$(CC) -c player.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

clean:
	rm -f *.o $(exe)