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
    }
    cout << "NULL";
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
    n1->next = NULL;

    display(n1);

    return 0;
}
