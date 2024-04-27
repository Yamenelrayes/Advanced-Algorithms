#include <iostream>
#include <algorithm>

using namespace std;

// in function i print the elements of the array
void printArray(const int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

// This function rearranges the elements around the pivot
void partition(int arr[], int low, int high, int k, int& i, int& j) {
    i = low - 1, j = high;  
    int p = low - 1, q = high;
    int v = arr[high]; 

    while (true) {
        while (arr[++i] < v);
        while (v < arr[--j])
            if (j == low)
                break; 

        if (i >= j) break;  
        swap(arr[i], arr[j]);  

        if (arr[i] == v) {
            p++;
            swap(arr[p], arr[i]);
        }
        if (arr[j] == v) {
            q--;
            swap(arr[j], arr[q]);
        }
    }
    swap(arr[i], arr[high]);
    j = i - 1;
    for (int k = low; k < p; k++, j--)
        swap(arr[k], arr[j]);
    i = i + 1;
    for (int k = high - 1; k > q; k--, i++)
        swap(arr[i], arr[k]);
}

// This function sorts the array using recursion and partitioning
void recursiveSort(int arr[], int low, int high, int k) {
    if (high <= low) return;  

    int i, j;
    partition(arr, low, high, k, i, j);  
    recursiveSort(arr, low, j, k);  
    recursiveSort(arr, i, high, k);  
}

int main() {
    int arr[] = { 3, 1, 12, 9, 4, 10, 54, 34, 12, 89 };
    int N = sizeof(arr) / sizeof(arr[0]);  

    cout << "Unsorted Array: ";
    printArray(arr, N);  

    cout << "Key = ";
    int k;
    cin >> k;  

    recursiveSort(arr, 0, N - 1, k);

    cout << "Output: ";
    printArray(arr, N); 

    return 0;
}
