#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node() {}

    Node(int d)
    {
        data = d;
        next = NULL;
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

Node *addAtHead(Node *head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    return head;
}

Node *addAtTail(Node *head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = newNode;
    return temp;
}

Node *insertAtPosition(Node *head, int data, int pos)
{
    Node *newNode = new Node(data);

    // Case 1: insert at head
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;

    // Traverse to (pos - 1)
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Position out of bounds" << endl;
            return head;
        }
        temp = temp->next;
    }

    // If temp is NULL, position is invalid
    if (temp == NULL)
    {
        cout << "Position out of bounds" << endl;
        return head;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node *userData()
{
    int data;
    cout << "Add a number to LL or -1 to exit" << endl;
    cin >> data;

    Node *head = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
    }
}

int main()
{
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node n5(50.5);

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = n4;
    n4->data = 40;
    n4->next = &n5;

    display(n3);

    // -- adding node at the beginning
    cout << "Adding at the beginning" << endl;
    Node *head = addAtHead(n1, 100);
    display(head);

    // -- adding node at the tail
    cout << "Adding at the beginning" << endl;
    head = addAtTail(head, 150);
    display(head);

    return 0;
}