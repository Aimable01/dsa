#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
            {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest])
            {
                largest = right;
            }
            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    void push(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        if (!heap.empty())
            return heap[0];
        throw out_of_range("Heap is empty");
    }

    bool empty()
    {
        return heap.empty();
    }

    int size()
    {
        return heap.size();
    }
};

int main()
{
    MaxHeap my_queue;

    my_queue.push(50);
    my_queue.push(100);
    my_queue.push(20);
    my_queue.push(300);
    my_queue.push(10);

    cout << "The elements in the priority queue are: " << endl;
    while (!my_queue.empty())
    {
        cout << my_queue.top() << endl;
        my_queue.pop();
    }

    cout << endl;
    cout << "The queue is empty or not: " << my_queue.empty() << endl;
    cout << "The queue size is: " << my_queue.size() << endl;

    return 0;
}
