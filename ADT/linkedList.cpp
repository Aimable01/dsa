#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the end
void insertAtEnd(Node *&head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the last node and insert the new node there
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = NULL;

    cout << "Before insertion:" << endl;
    display(n1);

    // Insert a new node at the end
    insertAtEnd(n1, 40);

    cout << "After insertion:" << endl;
    display(n1);

    return 0;
}
