
all: main

main: minqueue.o main.o
	g++ -std=c++11 minqueue.o test_minqueue.o -o test

main.o: minqueue.o test_minqueue.cpp
	g++ -std=c++11 -c test_minqueue.cpp 

minqueue.o: minqueue.cpp minqueue.h
		g++ -std=c++11 -c minqueue.cpp

clean:
	rm -f all *.o
