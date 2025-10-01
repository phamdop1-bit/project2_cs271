
all: main

main: minqueue.o usecase.o main.o
	g++ -std=c++11 minqueue.o usecase.o test_minqueue.o -o test

main.o: minqueue.o usecase.o test_minqueue.cpp
	g++ -std=c++11 -c test_minqueue.cpp 

usecase.o: minqueue.o usecase.cpp
	g++ -std=c++11 -c usecase.cpp 

minqueue.o: minqueue.cpp minqueue.h
		g++ -std=c++11 -c minqueue.cpp

clean:
	rm -f all *.o
