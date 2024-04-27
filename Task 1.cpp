#include <iostream>
#include <set>
using namespace std;

// This function removes duplicates from the array using a set
void removeDuplicates(char arr[], int& n) {
    set<char> seen;  // I'm using a set to keep track of characters I've already seen
    int writeUnique = 0;  // This is where I'll write the index for unique characters

    for (int i = 0; i < n; ++i) {
        // If the character is being seen for the first time add it to the 'seen' set and update the array
        if (seen.insert(arr[i]).second) {
            arr[writeUnique++] = arr[i]; 
        }
    }

    // I update the size of the array to the new size after removing duplicates
    n = writeUnique;
}

// This function just prints all elements of the array
void printArray(char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";  
    }
    cout << endl;  
}


int main() {
    char arr[] = { 'a', 'b', 'a', 'c', 'b', 'c', 'a', 'd', 'd', 'd', 'a', 'b' };
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << "Original array: ";
    printArray(arr, n); 

    removeDuplicates(arr, n); 

    cout << "Array without duplicates: ";
    printArray(arr, n);  

    return 0;  
}
