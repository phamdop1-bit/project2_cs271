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

void test_decrease_key(){

}

void test_min_heapify(){

}

void test_build_heap(){

}

void test_sort(){

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
    int len = 10;
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

}

void test_empty(){

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