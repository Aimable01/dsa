#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Print forward
    void printForward()
    {
        Node *curr = head;
        cout << "nullptr ⇄ ";
        while (curr)
        {
            cout << curr->data << " ⇄ ";
            curr = curr->next;
        }
        cout << "nullptr" << endl;
    }

    // Print backward
    void printBackward()
    {
        Node *curr = tail;
        cout << "nullptr ⇄ ";
        while (curr)
        {
            cout << curr->data << " ⇄ ";
            curr = curr->prev;
        }
        cout << "nullptr" << endl;
    }

    // Insert at beginning
    void pushFront(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void pushBack(int val)
    {
        Node *newNode = new Node(val);

        if (!tail)
        {
            head = tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Delete from beginning
    void popFront()
    {
        if (!head)
            return;

        Node *temp = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    // Delete from end
    void popBack()
    {
        if (!tail)
            return;

        Node *temp = tail;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    // Insert at specific position (0-based)
    void insertAt(int pos, int val)
    {
        if (pos == 0)
        {
            pushFront(val);
            return;
        }

        Node *curr = head;
        for (int i = 0; i < pos && curr; i++)
        {
            curr = curr->next;
        }

        if (!curr)
        {
            pushBack(val);
            return;
        }

        Node *newNode = new Node(val);

        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;
    }

    // Delete by value (first occurrence)
    void deleteByValue(int val)
    {
        Node *curr = head;

        while (curr && curr->data != val)
        {
            curr = curr->next;
        }

        if (!curr)
            return; // Not found

        // Update neighbors
        if (curr->prev)
            curr->prev->next = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;

        // Update head/tail if needed
        if (curr == head)
            head = curr->next;
        if (curr == tail)
            tail = curr->prev;

        delete curr;
    }

    // Search
    bool search(int val)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->data == val)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // Get size
    int size()
    {
        int count = 0;
        Node *curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // Reverse the list
    void reverse()
    {
        Node *curr = head;
        Node *temp = nullptr;

        // Swap prev and next for each node
        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // Move to original next (now prev)
        }

        // Swap head and tail
        temp = head;
        head = tail;
        tail = temp;
    }

    // Destructor (clean up memory)
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    // Insert
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);

    cout << "Forward:  ";
    list.printForward(); // nullptr ⇄ 5 ⇄ 10 ⇄ 20 ⇄ 30 ⇄ nullptr

    cout << "Backward: ";
    list.printBackward(); // nullptr ⇄ 30 ⇄ 20 ⇄ 10 ⇄ 5 ⇄ nullptr

    // Insert at position
    list.insertAt(2, 15);
    cout << "After insert 15 at index 2: ";
    list.printForward(); // 5 ⇄ 10 ⇄ 15 ⇄ 20 ⇄ 30

    // Delete
    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.printForward(); // 5 ⇄ 10 ⇄ 15 ⇄ 30

    // Reverse
    list.reverse();
    cout << "After reverse: ";
    list.printForward(); // 30 ⇄ 15 ⇄ 10 ⇄ 5

    // Size
    cout << "Size: " << list.size() << endl; // 4

    // Search
    cout << "Found 10: " << list.search(10) << endl; // 1
    cout << "Found 99: " << list.search(99) << endl; // 0

    return 0;
}