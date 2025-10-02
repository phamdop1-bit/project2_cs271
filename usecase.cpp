// #include "minqueue.h"
#include <string>
#include <sstream>
#include "minqueue.cpp"
using namespace std;

template <typename T>
string sliding_window(T arr[], int len, int window) {
    // Check for invalid inputs
    if (len == 0 || window <= 0 || window > len) {
        return "";
    }
    
    // Build result string directly
    stringstream ss;
    
    for (int i = 0; i <= len - window; i++) {
        // Create heap for current window
        MinQueue<T> window_heap(&arr[i], window);
        
        // Add space 
        if (i > 0) {
            ss << " ";
        }
        
        // Add minimum value to string
        ss << window_heap.min();
    }
    
    return ss.str();
}


// template string sliding_window<int>(int arr[], int len, int window);
