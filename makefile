
make: main, test

main: main.o
	g++ -o main.o

test: test_minqueue.o
	g++ -o test_minqueue.o

main.o: main.cpp usecase.cpp minqueue.cpp minqueue.h
	g++ -c main.cpp

test_minqueue.o: test_minqueue.cpp usecase.cpp minqueue.cpp minqueue.h
	g++ -c test_minqueue.cpp

clean:
	rm *.o
