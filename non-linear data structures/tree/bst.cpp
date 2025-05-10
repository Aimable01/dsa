
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        this->root = NULL;
    }
    Node *addNode(Node *subTree, int data, bool isRight)
    {
        Node *newNode = new Node(data);
        if (subTree == NULL)
        {
            root = newNode;
            return root;
        }
        if (isRight == true)
        {
            subTree->right = newNode;
        }
        else
            subTree->left = newNode;
        return newNode;
    }
    void display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
};

// Inorder traversal
void inorderTraversal(Node *node)
{
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    cout << node->data << " -> ";
    inorderTraversal(node->right);
}

// preorder traversal
void preorderTraversal(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " -> ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// postorder traversal
void postorderTraversal(Node *node)
{
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " -> ";
}

int main()
{

    BinaryTree bt;
    Node *root = bt.addNode(NULL, 1, false);
    Node *left = bt.addNode(root, 2, false);
    Node *rightt = bt.addNode(root, 3, true);
    Node *leftLeft = bt.addNode(left, 4, false);
    Node *leftRihgt = bt.addNode(left, 5, true);
    Node *righttLeft = bt.addNode(rightt, 6, false);
    Node *righttRight = bt.addNode(rightt, 7, true);
    bt.display(root);

    cout << "Inorder traversal ";
    inorderTraversal(root);
    cout << "\nPreorder traversal ";
    preorderTraversal(root);
    cout << "\nPostorder traversal ";
    postorderTraversal(root);

    return 0;
}
