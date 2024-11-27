#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        // Move elements of a[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main(){
    int arr[5] = {23, 5, 11, 7, 13};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
