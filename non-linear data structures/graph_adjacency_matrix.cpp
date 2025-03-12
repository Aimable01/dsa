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
        /**
         * Initializing the adjacency matrix
         */
        this->n = n;
        adj = new int *[n];

        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        display();
    }

    /* Adding edge to the graph */
    void addEdge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n"
                 << endl;
            return;
        }
        adj[origin - 1][destin - 1] = 1;
    }

    /* Delete an edge from the graph */
    void delete_edge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 0;
    }

    /* Print the graph */
    void display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
                cout << endl;
            }
        }
    }
};

int main()
{
    int nodes, max_edges, origin, destin;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    AdjacencyMatrix am(nodes);
    max_edges = nodes * nodes;

    for (int i = 0; i < max_edges; i++)
    {
        cout << "Edges number: " << i + 1 << endl;
        cout << "Enter edge(-1 -1 to exit): " << endl;
        cout << "Enter origin and destination vertices: " << endl;
        cin >> origin >> destin;
        if (origin == -1 || destin == -1)
            break;

        am.addEdge(origin, destin);
    }

    am.display();

    return 0;
}