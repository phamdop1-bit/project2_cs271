#include <iostream>
#include "minqueue.cpp"
#include "usecase.cpp"

void test_minqueue(){

}

void test_insert(){

}

void test_min(){

}

void test_extract_min(){

}

void test_decrease_key() {
    cout << "\n--- test_decrease_key ---\n";
    MinQueue<int> q;

    // Case 1: decrease_key on empty heap
    q.decrease_key(0, 5);  // should print error

    // Case 2: insert some values
    q.insert(20);
    q.insert(15);
    q.insert(30);

    cout << "Heap before decrease_key: " << q.min() << endl; // should be 15

    // Case 3: valid decrease
    q.decrease_key(2, 10);  // decrease 30 -> 10
    cout << "Heap after decrease_key(2,10): " << q.min() << endl; // should be 10

    // Case 4: invalid (increase instead of decrease)
    q.decrease_key(0, 50);  // should print error
}

// Test min_heapify edge cases
void test_min_heapify() {
    cout << "\n--- test_min_heapify ---\n";
    MinQueue<int> q;

    int arr[] = {10, 50, 20, 40, 80, 60};
    for (int i = 0; i < 6; i++) q.insert(arr[i]);

    // force a violation: set root higher
    q.set(0, 100);
    q.min_heapify(0);
    cout << "Min after fixing root=100: " << q.min() << endl; // should restore min
}

// Test build_heap edge cases
void test_build_heap() {
    cout << "\n--- test_build_heap ---\n";

    int arr[] = {50, 40, 30, 20, 10};
    int n = 5;

    MinQueue<int> q(arr, n);
    q.build_heap();

    cout << "Min after build_heap: " << q.min() << endl; // should be 10
}

// Test sort edge cases
void test_sort() {
    cout << "\n--- test_sort ---\n";

    int arr[] = {9, 4, 7, 1, 3};
    int n = 5;

    MinQueue<int> q(arr, n);
    q.build_heap();

    q.sort(arr);  // should sort array in ascending order

    cout << "Array after sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test_sliding_window(){
    
    //test 1
    int nums1[] = {1,2,3,4,5};
    int len = 5;
    int window = 1;
    string retstr = sliding_window(nums1, len, window);
    if(retstr != "1 2 3 4 5"){
        cout << "sliding window failed. Expected '1 2 3 4 5' but got: " << retstr << endl;
    }

    window = 2;
    retstr = sliding_window(nums1, len, window);
    if(retstr != "1 2 3 4"){
        cout << "sliding window failed. Expected '1 2 3 4' but got: " << retstr << endl;
    }

    //test 2
    int nums2[] = {0};
    len = 1;
    window = 1;
    retstr = sliding_window(nums1, len, window);
    if(retstr != "0"){
        cout << "sliding window failed. Expected '0' but got: " << retstr << endl;
    }

    window = 0;
    retstr = sliding_window(nums1, len, window);
    if(retstr != ""){
        cout << "sliding window failed. Expected '' but got: " << retstr << endl;
    }

    //test 3
    int nums3[] = {0,-25,1,63,5865,-45,0,326,40};
    len = 9;
    window = 3;
    retstr = sliding_window(nums1, len, window);
    if(retstr != "-25 -25 1 -45 -45 -45 0"){
        cout << "sliding window failed. Expected '-25 -25 1 -45 -45 -45 0' but got: " << retstr << endl;
    }
}

void test_to_string(){
    int nums[] = {9,1,2,6,5,4,3};
    int len = 7;
    MinQueue<int> numbers(nums,len);
    if(numbers.to_string() != "1 5 2 6 9 4 3"){
        cout << "To_string failed. Expected '1 5 2 6 9 4 3' but got: " << numbers.to_string() << endl;
    }

    MinQueue<int> blank;
    if(blank.to_string() != ""){
        cout << "To_string failed. Expected '' but got: " << blank.to_string() << endl;
    }

    MinQueue<string> string;
    string.insert("a");
    string.insert("b");
    string.insert("b");
    if(string.to_string() != "a b b"){
        cout << "To_string failed. Expected 'a b b' but got: " << string.to_string() << endl;
    }
    
}

void test_size(){
    int nums1[] = {9,1,2,6,5,4,3};
    int len = 7;
    MinQueue<int> numbers1(nums1,len);
    
    if(numbers1.size() != 7){
        cout << "Size failed. Expected 7 but got: " << numbers1.size() << endl;
        cout << "The elements are: " << numbers1.to_string() << endl;
    }

    int nums2[] = {0};
    len = 1;
    MinQueue<int> numbers2(nums2,len);

    if(numbers2.size() != 1){
        cout << "Size failed. Expected 1 but got: " << numbers2.size() << endl;
        cout << "The elements are: " << numbers2.to_string() << endl;
    }
    
    int junk = numbers2.extract_min();
    if(numbers2.size() != 0){
        cout << "Size failed. Expected 0 but got: " << numbers2.size() << endl;
        cout << "The elements are: " << numbers2.to_string() << endl;
    }

}

void test_empty(){
    int nums[] = {0};
    int len = 1;
    MinQueue<int> numbers(nums,len);

    if(numbers.empty()){
        cout << "Empty failed. Expected 1 item but was empty" << endl;
        cout << "The elements are: " << numbers.to_string() << endl;
    }
    
    int junk = numbers.extract_min();
    if(!(numbers.empty())){
        cout << "Empty failed. Expected 0 items but had something" << endl;
        cout << "The elements are: " << numbers.to_string() << endl;
    }

}

int main(){
    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_min_heapify();
    test_build_heap();
    test_sort();
    test_sliding_window();
    test_to_string();
    test_size();
    test_empty();
}
