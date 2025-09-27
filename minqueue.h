//#ifndef MINQUEUE_H
//#define MINQUEUE_H

#include <string>
#include <sstream>

template <typename T>
class MinQueue {
private:
    T* heap;
    int capacity;
    int heap_size;
    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
public:
    // Constructors
    MinQueue(void);
    MinQueue(T* A, int n);
    
    // Destructor
    ~MinQueue();
    
    // Copy constructor and assignment operator
    MinQueue(const MinQueue& other);
    MinQueue<T> operator=(const MinQueue& other);
    
    // Priority Queue operations
    void insert(T x);
    T min();
    T extract_min();
    void decrease_key(int i, T k);
    
    // Heap operations
    void min_heapify(int i);
    void build_heap();
    void sort(T* A);
    
    // Utility methods
    std::string to_string();
    void set(int i, T val);
    void allocate(int n);
    int size() { return heap_size; }
    bool empty() { return heap_size == 0; }
};

#endif
