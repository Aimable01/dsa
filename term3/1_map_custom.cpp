#include <iostream>
using namespace std;

struct Node
{
    string key;
    int value;
    Node *left, *right;

    Node(string k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class orderedMap
{
private:
    Node *root = nullptr;

    Node *insert(Node *node, string key, int value)
    {
        if (!node)
            return new Node(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value;

        return node;
    }

public:
    void put(string key, int value)
    {
        root = insert(root, key, value);
    }
};