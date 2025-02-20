#include <iostream>
using namespace std;

// the node struct
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

// Function to display the linked list
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

// Function to insert at head
void insertAtHead(Node **head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at tail
void insertAtTail(Node **head, int val)
{
    Node *newNode = new Node(val);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert at any position
void insertAtAny(Node **head, int val, int position)
{
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1)
    {
        insertAtHead(head, val);
        return;
    }

    Node *newNode = new Node(val);

    Node *temp = *head;
    for ()
}

int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;
    display(n1);

    cout << endl
         << "Insert element at head" << endl;
    Node *head = NULL;
    head = n1;
    insertAtHead(&head, 5);
    display(head);

    cout << endl
         << "Insert element at tail" << endl;
    insertAtTail(&head, 40);
    display(head);

    return 0;
}