#include <iostream>
using namespace std;

// node structure for the linked list
struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL; // initialize the stack as empty
    }

    // push operation
    void push(int value)
    {
        Node *newNode = new Node(value); // create a new node
        newNode->next = top;             // link the new node with the current top
        top = newNode;                   // update the top pointer to point to the new node
        cout << value << " pushed to the stack" << endl;
    }

    // pop operation
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        Node *temp = top; // store the current top node
        top = top->next;  // update top to the next node
        cout << temp->data << " popped from the stack" << endl;
        delete temp;
    }

    // check if empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // display the elements of the stack
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    stack.pop();

    stack.display();

    return 0;
}