#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // create temporary vectors
    vector<int> left(leftSize), right(rightSize);

    // copy data into vectors
    for (int i = 0; i < leftSize; i++)
    {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    // merge the two vectors
    int i = 0, j = 0, k = low;

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

    // copy remaining elements
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

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {23, 5, 11, 7, 13};

    mergeSort(arr, 0, arr.size() - 1);

    // print sorted array
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}