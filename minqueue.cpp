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
/*
Pre-Conditions: A is an array
Post_Conditions: this min-queue is equivalent to A
*/
template <class T>
    MinQueue<T>::MinQueue(T* A, int n){
        heapsize = n;
        capasity = n;
        head = new T[capasity];
        for(int i=0; i<heapsize; i++){
            heap[i] = A[i];
        }
        build_heap()
}

// Destructor
/*
Pre-Conditions: None
Post_Conditions: Dealocates all memory of the queue
*/
template <class T>
    MinQueue<T>::~MinQueue(){
        clear();
}

// Copy constructor and assignment operator
/*
Pre-Conditions: other is a sorted MinQueue
Post_Conditions: this min-queue is equivalent to other
*/
template <class T>
    MinQueue<T>::MinQueue(const MinQueue& other){
        heapsize = 0;
        capasity = 0;
        heap = new T[capasity];
        DeepCopy(other);
}

/*
Pre-Conditions: other is a sorted MinQueue
Post_Conditions: this min-queue is equivalent to other
*/
template <class T>
    MinQueue<T>& MinQueue<T>::operator=(const MinQueue& other){
        DeepCopy(other);
        return *this;
}

// Priority Queue operations
template <class T>
void MinQueue<T>::insert(T x) {
    if (heap_size == capacity) {
        // resize: double the capacity or start with 1
        int newCap = (capacity == 0 ? 1 : capacity * 2);
        allocate(newCap);
    }
    heap_size++;
    int i = heap_size - 1;
    heap[i] = x;

    // Fix the min-heap property upwards
    while (i > 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <class T>
T MinQueue<T>::min() {
    if (heap_size <= 0) {
        std::cout << "Error: Heap is empty";
        return T();
    }
    return heap[0];
}

template <class T>
T MinQueue<T>::extract_min() {
    if (heap_size <= 0) {
        std::cout << "Error: Heap is empty";
        return T();
    }
    if (heap_size == 1) {
        heap_size--;
        return heap[0];
    }

    T root = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    min_heapify(0);

    return root;
}

template <class T>
void MinQueue<T>::decrease_key(int i, T k) {
    if (i < 0 || i >= heap_size) {
        std::cout << "Error: Index out of bounds";
        return T();
    }
    if (k >= heap[i]) {
        std::cout << "Error: New Key is Greater than/equal to current key";
        return T();
    }

    heap[i] = k;
    // Fix upwards
    while (i > 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


// Heap operations
// Precondition: heap contains heap_size elements
// Postcondition: heap satisfies min-heap property
template <class T>
void MinQueue<T>::build_heap(){
	for (int i = (heap_size - 1) / 2; i >= 0; i--) {
    min_heapify(i);
    }
}

// Precondition: heap contains heap_size elements
// Postcondition: heap satisfies min-heap property
template <class T>
void MinQueue<T>::min_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if (r < heap_size && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        min_heapify(smallest);
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
/*
Pre-Conditions: Wanting to get rid of heap
Post_Conditions: Dealocates all memory of heap
*/
template <class T>
    void MinQueue<T>::clear(void){
        T *current = head;
        delete current;
        head = NULL;
        capasity = 0;
        size = 0;
}

/*
Pre-Conditions: other is a sorted MinQueue, this heap is defined
Post_Conditions: this min-queue is equivalent to other
- specificly it clears the current heap and copies the new one over
*/
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
