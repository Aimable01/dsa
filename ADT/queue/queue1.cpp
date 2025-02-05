#include "iostream"

using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == n - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "The removed element in the queue is " << queue[front] << endl;
        front++;
    }
}

int getFrontElement()
{
    if (front == -1 || front > rear)
    {
        return 0;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << "The element at index" << i << "=" << queue[i] << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    dequeue();
    dequeue();
    display();

    return 0;
}