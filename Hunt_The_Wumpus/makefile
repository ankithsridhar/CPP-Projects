CC=g++ -std=c++11
exe=prog

$(exe): wumpus.o gold.o bats.o pit.o event.o room.o game.o wumpus.h gold.h bats.h pit.h event.h room.h game.h main.cpp 
	$(CC) wumpus.o gold.o bats.o pit.o event.o room.o game.o main.cpp -std=c++11 -o $(exe)

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

pit.o: pit.h pit.cpp
	$(CC) -c pit.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

game.o: game.h game.cpp player.h
	$(CC) -c game.cpp -std=c++11

clean:
	rm -f *.o $(exe)