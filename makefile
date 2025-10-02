
make: main, test

main: main.o
	g++ main.o -o main 

test: test_minqueue.o
	g++ test_minqueue.o -o test_minqueue
	
main.o: main.cpp usecase.cpp minqueue.cpp minqueue.h
	g++ -c main.cpp

test_minqueue.o: test_minqueue.cpp usecase.cpp minqueue.cpp minqueue.h
	g++ -c test_minqueue.cpp

clean:
	rm *.o
