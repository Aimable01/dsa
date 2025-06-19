#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
    }

    // return
};