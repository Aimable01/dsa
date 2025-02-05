#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    int count()
    {
        // some logic
    }
    bool isEmpty()
    {
        return size == 0;
    }

    // t0 enqueue
    void enqueue(int ele)
    {
        Node *n = new Node(ele);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }

        size++;
    }

    // to dequeue
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    Queue *q = new Queue();
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70);
    q->display();

    cout << q->front() << endl;
    q->dequeue();
    q->dequeue();
    q->dequeue();

    cout << q->front() << endl;
    cout << q->getSize() << endl;
    cout << q->isEmpty() << endl;

    q->enqueue(70);
    q->enqueue(60);
    q->display();
    q->dequeue();
    q->dequeue();
    cout << q->front() << endl;
    cout << q->getSize() << endl;

    while (!q->isEmpty())
    {
        cout << q->front() << endl;
        q->dequeue();
    }
    cout << q->getSize() << endl;
    cout << q->isEmpty() << endl;
    return 0;
}