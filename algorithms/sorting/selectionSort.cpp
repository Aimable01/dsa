#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n - 1;i++){
        int targetIndex = i;
        for (int j = i + 1; j < n; j++){
            if(a[j]<a[targetIndex]){
                targetIndex = j;
            }
        }
        swap(a[i], a[targetIndex]);
    }
}

int main(){
    int arr[5] = {23, 5, 11, 7, 13};
    selectionSort(arr, 5);
    for (int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}