#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {-5, 2, 3, 5, 6, 7, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, 3);
    cout << "found at index: " << result << endl;
}