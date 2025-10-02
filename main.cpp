#include <iostream>
#include <string>
#include <vector>
#include "usecase.cpp"

using namespace std;

// Forward declaration of sliding_window function
template <typename T>
string sliding_window(T arr[], int len, int window);

int main() {
    cout << "Please enter elements single spaced appart." << endl << "Input elements: ";

    string line;
    getline(cin, line);
    
    vector<int> items;
    
    int spacePos = 0;
    while(line!=""){
        spacePos = line.find(" ");
        if(spacePos != string::npos){
            string part = line.substr(0,spacePos);
            items.push_back(stoi(part));
            line = line.substr(spacePos+1);
        }else{
            items.push_back(stoi(line));
            line = "";
        }
    }

    int size = items.size();
    int* insert = new int[size];
    for(int i=0; i<size; i++){
        insert[i] = items[i];
    }

    cout << endl << "What is the lengh of the window: ";

    int windowLen;

    cin >> windowLen;

    string output = sliding_window(insert, size, windowLen);

    cout << "The mins of the window as it slides across are as follows: " << endl << output  << endl;

    return 0;
}
