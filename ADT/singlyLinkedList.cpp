#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node() {}

    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

void display(Node<double> *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node<double> *n1 = new Node<double>();
    Node<double> *n2 = new Node<double>();
    Node<double> *n3 = new Node<double>();
    Node<double> *n4 = new Node<double>();
    Node<double> n5(50.5);

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = n4;
    n4->data = 40;
    n4->next = &n5;

    display(n3);

    return 0;
}