#ifndef MINQUEUE_CPP
#define MINQUEUE_CPP

#include <string>
#include <sstream>
#include "minqueue.h"

using namespace std;

// Constructors
/*
Pre-Conditions: The funciton is called
Post_Conditions: a empty MinQueue is made
*/
template <class T>
    MinQueue<T>::MinQueue(void){
        heapsize = 0;
        capasity = 0;
        heap = new T[capasity];
}
template <class T>
    MinQueue<T>::MinQueue(T* A, int n){
        heapsize = n;
        capasity = n;
        head = new T[capasity];
        for(int i=0; i<heapsize; i++){
            heap[i] = A[i];
        }

}

// Destructor
template <class T>
    MinQueue<T>::~MinQueue(){
        clear();
}

// Copy constructor and assignment operator
template <class T>
    MinQueue<T>::MinQueue(const MinQueue& other){
        heapsize = 0;
        capasity = 0;
        heap = new T[capasity];
        DeepCopy(other);
}

template <class T>
    MinQueue<T>& MinQueue<T>::operator=(const MinQueue& other){
        DeepCopy(other);
        return *this;
}

// Priority Queue operations
template <class T>
    void MinQueue<T>::insert(T x){

}

template <class T>
    T MinQueue<T>::min(){

}

template <class T>
    T MinQueue<T>::extract_min(){

}

template <class T>
    void MinQueue<T>::decrease_key(int i, T k){

}


// Heap operations
template <class T>
    void MinQueue<T>::min_heapify(int i){

}

// Precondition: heap contains heap_size elements
// Postcondition: heap satisfies min-heap property
template <class T>
    void MinQueue<T>::build_heap(){
		for (int i = (heap_size - 1) / 2; i >= 0; i--) {
        min_heapify(i);
    }
}

// Precondition: A is a valid array with at least heap_size elements
// Postcondition: A contains the elements of the heap in ascending order
template <class T>
    void MinQueue<T>::sort(T* A){
	MinQueue<T> temp_heap(*this);
    
    for (int i = 0; i < heap_size; i++) {
        A[i] = temp_heap.extract_min();
    }
}

// Utility methods
// Precondition: None
// Postcondition: Returns string representation of heap elements separated by spaces
template <class T>
    std::string MinQueue<T>::to_string(){
    	if (heap_size == 0) {
        	return "";
    	}
    
    	std::stringstream ss;
    	for (int i = 0; i < heap_size; i++) {
        	if (i > 0) ss << " ";
        	ss << heap[i];
    	}
    	return ss.str();
}

// Precondition: 0 <= i < capacity
// Postcondition: heap[i] is set to val
template <class T>
    void MinQueue<T>::set(int i, T val){
	if (i < 0 || i >= capacity) {
        throw std::out_of_range("Index out of bounds");
    }
    heap[i] = val;
}

// Precondition: n > 0
// Postcondition: heap capacity is at least n
template <class T>
    void MinQueue<T>::allocate(int n){
		if (n > capacity) {
        T* new_heap = new T[n];
        for (int i = 0; i < heap_size; i++) {
            new_heap[i] = heap[i];
        }
        delete[] heap;
        heap = new_heap;
        capacity = n;
    }
}

//healper funciton
template <class T>
    void MinQueue<T>::clear(void){
        T *current = head;
        delete current;
        head = NULL;
        capasity = 0;
        size = 0;
}

template <class T>
    void MinQueue<T>::DeepCopy(const MinQueue& other){
	    clear();
        capasity = other.capasity;
        heapsize = other.heapsize;
        heap = new T[capasity];
        for(int i=0; i<heapsize; i++){
            heap[i] = other.heap[i];
        }
}



#endif
