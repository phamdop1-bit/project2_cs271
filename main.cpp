#include "minqueue.h"
#include <iostream>
#include <string>

using namespace std;

// Forward declaration of sliding_window function
template <typename T>
string sliding_window(T arr[], int len, int window);

void test_sliding_window() {
    cout << "Test sliding window " << endl << endl;

    // Test case 1 from the specification
    cout << "Test Case 1:" << endl;
    int nums1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int len1 = 8;
    int k1 = 3;

    cout << "Input: [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i];
        if (i < len1 - 1) cout << ", ";
    }
    cout << "], k = " << k1 << endl;

    string result1 = sliding_window(nums1, len1, k1);
    cout << "Output: [" << result1 << "]" << endl;
    cout << "Expected: [-1, -3, -3, -3, 3, 3]" << endl;

    if (result1 == "-1 -3 -3 -3 3 3") {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;

    // Test case 2 from the specification
    cout << "Test Case 2:" << endl;
    int nums2[] = {1};
    int len2 = 1;
    int k2 = 1;

    cout << "Input: [";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i];
        if (i < len2 - 1) cout << ", ";
    }
    cout << "], k = " << k2 << endl;

    string result2 = sliding_window(nums2, len2, k2);
    cout << "Output: [" << result2 << "]" << endl;
    cout << "Expected: [1]" << endl;

    if (result2 == "1") {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;

    // Additional test case 3
    cout << "Test Case 3:" << endl;
    int nums3[] = {5, 3, 4, 1, 2};
    int len3 = 5;
    int k3 = 2;

    cout << "Input: [";
    for (int i = 0; i < len3; i++) {
        cout << nums3[i];
        if (i < len3 - 1) cout << ", ";
    }
    cout << "], k = " << k3 << endl;

    string result3 = sliding_window(nums3, len3, k3);
    cout << "Output: [" << result3 << "]" << endl;
    cout << "Expected: [3, 3, 1, 1]" << endl;

    if (result3 == "3 3 1 1") {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;
}

int main() {

    test_sliding_window();

    cout << "Test Passed" << endl;
    return 0;
}
