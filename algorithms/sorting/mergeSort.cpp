#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // create temporary arrays
    int left[leftSize], right[rightSize];

    // copy elements into them arrays
    for (int i = 0; i < leftSize; i++)
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    // merge the two arrays
    int i = 0,
        j = 0,
        k = start;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements
    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int arr[5] = {23, 5, 11, 7, 13};

    mergeSort(arr, 0, 4);

    // Output the sorted array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}