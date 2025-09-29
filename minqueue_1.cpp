#ifndef MINQUEUE_CPP
#define MINQUEUE_CPP

#include <string>
#include <sstream>
#include <iostream>

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

template <class T>
    void MinQueue<T>::build_heap(){

}

template <class T>
    void MinQueue<T>::sort(T* A){

}

// Utility methods
template <class T>
    std::string MinQueue<T>::to_string(){

}

template <class T>
    void MinQueue<T>::set(int i, T val){

}

template <class T>
    void MinQueue<T>::allocate(int n){

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