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
                adj[i][j] = 0; // Initialize with 0 (no edge)
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

    /* Adding an edge with a weight */
    void addEdge(int origin, int destin, int weight)
    {
        if (origin < 1 || destin < 1 || origin > n || destin > n)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = weight;
        adj[destin - 1][origin - 1] = weight; // Remove this for a directed graph
    }

    /* Deleting an edge */
    void deleteEdge(int origin, int destin)
    {
        if (origin < 1 || destin < 1 || origin > n || destin > n)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 0;
        adj[destin - 1][origin - 1] = 0; // Remove this for a directed graph
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
            cout << endl;
        }
    }
};

int main()
{
    int nodes = 5, origin, destin, weight;
    AdjacencyMatrix am(nodes);

    cout << "Enter edges in the format (origin destination weight), enter -1 -1 -1 to stop:\n";
    while (true)
    {
        cin >> origin >> destin >> weight;
        if (origin == -1 || destin == -1 || weight == -1)
            break;
        am.addEdge(origin, destin, weight);
    }

    am.display();
    return 0;
}
