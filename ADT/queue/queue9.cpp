#include <iostream>
using namespace std;
struct Que
{
    int *arr;
    int front, rear, capacity, size;
    Que(int cap)
    {
        capacity = cap;
        front = rear = -1;
        size = 0;
        arr = new int[capacity];
    }
    void enque(int val)
    {
        if (isFull())
        {
            int *newArr = new int[capacity * 2];
            for (int i = front; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            rear = capacity - 1;
            capacity = capacity * 2;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = val;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Que is empty" << endl;
        }
        else
        {
            cout << "The removed element in th eque is " << arr[front] << endl;
            front++;
            size--;
        }
    }
    int count()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int getFrontElement()
    {
        if (front == -1 || front > rear)
        {
            return 0;
        }
        else
        {
            return arr[front];
        }
    }
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Que is empty" << endl;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << "The element at index " << i << "=" << arr[i] << endl;
        }
    }
};
int main()
{
    Que *q = new Que(5);
    cout << "Start adding element" << endl;
    q->enque(10);
    q->enque(20);
    q->enque(30);
    q->enque(40);
    q->enque(50);
    q->enque(60);
    q->enque(70);
    cout << "end of adding elements" << endl;
    q->display();
    q->dequeue();
    q->dequeue();
    q->display();
    cout << "Adding after removing 2 elements" << endl;
    q->enque(66);
    q->enque(77);
    q->display();
    q->dequeue();
    q->dequeue();
    return 0;
}