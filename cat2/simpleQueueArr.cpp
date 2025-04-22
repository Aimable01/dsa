#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == MAX - 1);
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "overflow";
            return;
        }
        if (isEmpty)
        {
            front = 0;
        }
        arr[++rear] = val;
    }

    int dequeue()
    {
        if (isEmpty)
        {
            cout << "Queue is emtpy";
            return;
        }

        int val = arr[front++];
        return val;
    }
};