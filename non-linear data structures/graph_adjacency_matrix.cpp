#include <iostream>
using namespace std;

class AdjacencyMatrix
{
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n)
    {
        this->n = n;
        adj = new int *[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0; // Initialize with 0
            }
        }
    }

    ~AdjacencyMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] adj[i];
        }
        delete[] adj;
    }

    /* Adding an edge to the graph */
    void addEdge(int origin, int destin)
    {
        if (origin < 1 || destin < 1 || origin > n || destin > n)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 1;
    }

    /* Deleting an edge from the graph */
    void deleteEdge(int origin, int destin)
    {
        if (origin < 1 || destin < 1 || origin > n || destin > n)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 0;
    }

    /* Printing the adjacency matrix */
    void display()
    {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl; // Fix newline issue
        }
    }
};

int main()
{
    int nodes, max_edges, origin, destin;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1); // Adjusted for directed graph

    for (int i = 0; i < max_edges; i++)
    {
        cout << "Edges number: " << i + 1 << endl;
        cout << "Enter edge (-1 -1 to exit): ";
        cin >> origin >> destin;

        if (origin == -1 || destin == -1)
            break;

        am.addEdge(origin, destin);
    }

    am.display();

    return 0;
}
