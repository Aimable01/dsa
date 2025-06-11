#include <iostream>
using namespace std;

// struct for bst
struct Node
{
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    // to insert
    Node *insertHelper(Node *node, int val)
    {
        // if current node is null create a new node
        if (node == nullptr)
        {
            return new Node(val);
        }

        // if less, go left
        if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }

        // if greater, go right
        if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }

        return node; // return the unchanged node
    }

    // to find the minimum
    Node *minimum(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }

        return node;
    }

    // to delete node
    Node *delelteHelper(Node *node, int val)
    {
        // node not found
        if (node == nullptr)
        {
            return nullptr;
        }

        // find node to delete
        if (val < node->data)
        {
            return delelteHelper(node->left, val);
        }
        else if (val > node->data)
        {
            return delelteHelper(node->right, val);
        }
        else
        {
            // node with only one child or no child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
        }

        return node;
    }

    // to search
    bool searchHelper(Node *node, int val)
    {
        if (node == nullptr)
            return false;

        if (node->data == val)
            return true;

        if (val < node->data)
            return searchHelper(node->left, val);

        return searchHelper(node->right, val);
    }

    // helper functions for traversals
    // inorder traversal LDR
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // preorder traversal DLR
    void preorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // postorder traversal LRD
    void postorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
};