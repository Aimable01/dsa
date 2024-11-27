#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int check = 0;
        for (int j = 0; j < n - 1 - i; j++){
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                check = 1;
            }
            cout << "i=" << i << " j=" << j << " i*j=" << i * j << endl;
        }
        if (check == 0) break;
    }
}

int main(){
    int arr[5] = {23, 5, 11, 7, 13};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}