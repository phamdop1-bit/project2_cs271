
all: main

main: minqueue.o usecase.o main.o
	g++ minqueue.o usecase.o test_minqueue.o -o test

main.o: minqueue.o usecase.o test_minqueue.cpp
	g++ -c test_minqueue.cpp 

usecase.o: minqueue.o usecase.cpp
	g++ -c usecase.cpp 

minqueue.o: minqueue.cpp minqueue.h
	g++ -c minqueue.cpp

clean:
	rm -f all *.o
