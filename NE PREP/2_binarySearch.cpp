#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        if (arr[mid] > target)
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binarySearch(arr, 9, 3);

    return 0;
}