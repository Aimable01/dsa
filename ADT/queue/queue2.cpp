#include <iostream>
using namespace std;

class Queue
{
private:
    int *queue;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        queue = new int[capacity];
        size = 0;
    }

    ~Queue()
    {
        delete[] queue;
    }

    void enqueue(int val)
    {
        if (rear == capacity - 1)
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
            size++;
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
            size--;
            if (front > rear)
            {
                front = rear = -1; // Reset the queue when the last element is dequeued
            }
        }
    }

    int getFrontElement()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate an empty queue
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
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "The element at index " << i << " = " << queue[i] << endl;
            }
        }
    }

    int count()
    {
        return size;
    }
};

int main()
{
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Number of elements in the queue: " << q.count() << endl;

    return 0;
}