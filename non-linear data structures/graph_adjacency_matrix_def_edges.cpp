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
         * Initializing an empty matrix
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
    void add_edge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge! Vertices must be between 1 and " << n << endl;
            return;
        }
        adj[origin - 1][destin - 1] = 1;
        cout << "Edge added successfully from vertex " << origin << " to vertex " << destin << endl;
    }

    void delete_edge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge! Vertices must be between 1 and " << n << endl;
            return;
        }
        adj[origin - 1][destin - 1] = 0;
        cout << "Edge deleted successfully from vertex " << origin << " to vertex " << destin << endl;
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
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes, edges, origin, destin;

    cout << "Enter number of nodes (must be positive): ";
    cin >> nodes;

    if (nodes <= 0)
    {
        cout << "Number of nodes must be positive!" << endl;
        return 1;
    }

    cout << "Enter number of edges (must not exceed " << nodes * nodes << "): ";
    cin >> edges;

    if (edges <= 0 || edges > (nodes * nodes))
    {
        cout << "Invalid number of edges! Must be between 1 and " << nodes * nodes << endl;
        return 1;
    }

    AdjacencyMatrix am(nodes);
    cout << "\nInitial adjacency matrix:" << endl;
    am.display();

    for (int i = 0; i < edges; i++)
    {
        cout << "\nEdge " << i + 1 << " of " << edges << endl;
        cout << "Enter origin and destination vertices (1 to " << nodes << ", or -1 -1 to exit): ";
        cin >> origin >> destin;

        if (origin == -1 && destin == -1)
        {
            cout << "Exiting edge input..." << endl;
            break;
        }

        am.add_edge(origin, destin);
    }

    cout << "\nFinal adjacency matrix:" << endl;
    am.display();

    return 0;
}