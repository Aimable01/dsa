#include <iostream>
using namespace std;

// max size of stack
#define MAX_SIZE 100

class Stack
{
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack()
    {
        top = -1; // initialize the stack as empty
    }

    // push operation
    void push(int val)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack overflow! Cannot insert " << val << endl;
            return;
        }
        arr[++top] = val; // increment top and add the value
        cout << "Pushed to stack" << endl;
    }

    // pop operation
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        int value = arr[top--]; // decrement top and get the value
        cout << value << " popped from the stack" << endl;
    }

    // peek operation
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top]; // the top element
    }

    // check if the stack is empty
    bool isEmpty()
    {
        return top < 0;
    }

    // check if stack is full
    bool isfull()
    {
        return (top >= MAX_SIZE - 1);
    }

    // display the stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
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