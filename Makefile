# Write your own makefile that generates two executables- the first should be called game
# (expected output for game is described later). The second should be called tests and must RUN
# (not just compile) all the test code to unit test your classes and methods


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
	./bstTests a0.txt b0.txt
	./bstTests a1.txt b1.txt
	./bstTests a2.txt b2.txt
	./bstTests a3.txt b3.txt
	./bstTests acards.txt bcards.txt

bstTests: ${COMMON_OBJECT_FILES}
	g++ -Wall -Wno-uninitialized ${LDFLAGS} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o