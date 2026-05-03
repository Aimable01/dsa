#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int myArr[9] = {2, 3, 7, 5, 8, 3, 6, 9, 4};
    insertionSort(myArr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << myArr[i] << ",";
    }

    return 0;
}
