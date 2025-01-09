#include <iostream>
using namespace std;

int main()
{
    /*
    int i = 20;
    cout << &i << endl;
    int *p = &i;
    cout << p << endl;
    cout << *p << endl;
    char c = 'd';
    char *p2 = &c;
    cout << "The size of i: " << sizeof(i) << endl;
    cout << "The size of c: " << sizeof(c) << endl;
    cout << "The size of p: " << sizeof(p) << endl;
    cout << "The size of p2: " << sizeof(p2) << endl;
    */

    int size = 3;
    int numbers[3] = {10, 20, 30};
    int *ptr = numbers;
    cout << "The address of element at i= " << 0 << " is " << numbers << " and value is " << numbers[0] << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "The address of element at i= " << i << " is " << (ptr + i) << " and value is " << *(ptr + i) << endl;
    }

    cout << "Using pointers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "The address of element at i= " << i << " is " << (numbers + i) << " and value is " << numbers[i] << endl;
    }

    cout << "Using array as pointers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "The address of element at i= " << i << " is " << (numbers + i) << " and value is " << *(numbers + i) << endl;
    }

    cout << *numbers;

    return 0;
}