#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Declare priority queue
    priority_queue<int> my_queue;

    // Insert elements
    my_queue.push(50);
    my_queue.push(100);
    my_queue.push(20);
    my_queue.push(300);
    my_queue.push(10);

    // Print the elements
    cout << "The elements in the priority queue are: " << endl;

    while (!my_queue.empty())
    {
        cout << my_queue.top() << endl; // top most priority

        // pop the top element
        my_queue.pop();
    }

    cout << endl;

    // empty
    cout << "The queue is empty or not: " << my_queue.empty() << endl;

    // size
    cout << "The queue size is: " << my_queue.size() << endl;

    return 0;
}