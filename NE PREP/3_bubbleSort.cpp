#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int myArr[9] = {2, 3, 7, 5, 8, 3, 6, 9, 4};
    bubbleSort(myArr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << myArr[i] << ",";
    }

    return 0;
}