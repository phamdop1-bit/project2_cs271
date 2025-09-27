#ifndef MINQUEUE_CPP
#define MINQUEUE_CPP

#include <string>
#include <sstream>
#include "minqueue.h"

using namespace std;

// Constructors

template <class T>
    MinQueue<T>::MinQueue(void){

}
template <class T>
    MinQueue<T>::MinQueue(T* A, int n){

}

// Destructor
template <class T>
    MinQueue<T>::~MinQueue(){

}

// Copy constructor and assignment operator
template <class T>
    MinQueue<T>::MinQueue(const MinQueue& other){

}

template <class T>
    MinQueue<T>& MinQueue<T>::operator=(const MinQueue& other){

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

#endif