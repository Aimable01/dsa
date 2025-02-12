#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T ele)
    {
        Node<T> *newNode = new Node<T>(ele);
        newNode->next = head;
        head = newNode;
        size++;
    }
};