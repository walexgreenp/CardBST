CXX_FLAG = --std=c++11 -g

BINARIES = bstTests

COMMON_OBJECT_FILES = cards.o main.o

all: game

main.o: main.cpp cards.h
	g++ main.cpp -c

cards.o: cards.cpp cards.h
	g++ cards.cpp -c

game: main.o cards.o
	g++ main.o cards.o -o game


tests: ${BINARIES}
	./bstTests txtFiles/a0.txt txtFiles/b0.txt
	./bstTests txtFiles/a1.txt txtFiles/b1.txt
	./bstTests txtFiles/a2.txt txtFiles/b2.txt
	./bstTests txtFiles/a3.txt txtFiles/b3.txt
	./bstTests txtFiles/acards.txt txtFiles/bcards.txt
	./bstTests txtFiles/aCompare.txt txtFiles/bCompare.txt


bstTests: ${COMMON_OBJECT_FILES}
	g++ -Wall -Wno-uninitialized ${LDFLAGS} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
