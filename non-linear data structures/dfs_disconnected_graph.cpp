#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function to traverse the graph
void printDFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    cout << "Visiting node: " << sv << endl; // Print the current node
    visited[sv] = true;                      // Mark the current node as visited
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        // If there is an edge and the node is not visited
        if (v[sv][i] == 1 && visited[i] == false)
        {
            printDFS(v, i, visited); // Recursively visit the node
        }
    }
}

// DFS function to handle disconnected graphs and count connected components
void DFS(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<bool> visited(n, false); // Initialize visited array
    int count = 0;                  // Counter for connected components

    cout << "\nStarting DFS traversal..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++; // Increment component count
            cout << "\nNew connected component found! Starting DFS from node: " << i << endl;
            printDFS(matrix, i, visited); // Perform DFS for the current component
        }
    }
    cout << "\nDFS traversal complete!" << endl;
    cout << "Number of connected components in the graph: " << count << endl;
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    // Initialize adjacency matrix with 0
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // Input edges and populate adjacency matrix
    cout << "\nEnter the edges (format: node1 node2):" << endl;
    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        cout << "Edge " << i << ": ";
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1; // Since the graph is undirected
    }

    cout << "\nDFS Traversal:" << endl;
    DFS(matrix); // Perform DFS traversal

    return 0;
}