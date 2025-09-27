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