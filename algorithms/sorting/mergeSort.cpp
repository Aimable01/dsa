#include <iostream>
#include<array>
using namespace std;

void mergeArrays(int x[], int y[], int a[], int s, int e) {
    int mid = (s + e) / 2;
    int i = s;         // Starting index for left subarray
    int j = mid + 1;   // Starting index for right subarray
    int k = s;         // Starting index for merged array

    while (i <= mid && j <= e) {
        // Compare and merge elements
        if (x[i] < y[j]) {
            a[k] = x[i];
            i++;
        } else {
            a[k] = y[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        a[k] = x[i];
        k++;
        i++;
    }

    // Copy remaining elements from the right subarray
    while (j <= e) {
        a[k] = y[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int s, int e) {
    if (s >= e) {
        return; // Base case: array has one or zero elements
    }

    int mid = (s + e) / 2;
    int x[100], y[100]; // Temporary arrays for left and right halves

    // Copy elements to the left subarray
    for (int i = s; i <= mid; i++) {
        x[i] = a[i];
    }

    // Copy elements to the right subarray
    for (int i = mid + 1; i <= e; i++) {
        y[i] = a[i];
    }

    // Recursively sort the left and right subarrays
    mergeSort(x, s, mid);
    mergeSort(y, mid + 1, e);

    // Merge the two sorted halves
    mergeArrays(x, y, a, s, e);
}

int main() {
    int a[] = {7, 3, 10, 5, 6, 2, -5}; // Fixed array initialization

    int size = end(a) - begin(a);
    cout << size << endl;

    mergeSort(a, 0, 6); // Sorting the array

    // Output the sorted array
    for (int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }

    return 0;
}