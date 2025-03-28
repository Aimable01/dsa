#include "iostream"

using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

class Queue
{
public:
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
};

int main()
{
    Queue q;
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

    return 0;
}