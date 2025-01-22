#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *deleteAtHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main()
{
    Node *n1 = new Node(17);
    Node *n2 = new Node(10);
    Node *n3 = new Node(15);
    Node *n4 = new Node(25);
    Node *n5 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    cout << "The full list" << endl;
    display(n1);

    cout << "After deleting" << endl;
    Node *test = deleteAtHead(n1);

    display(test);

    return 0;
}