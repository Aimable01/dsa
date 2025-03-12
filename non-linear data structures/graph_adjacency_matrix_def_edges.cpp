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
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 1;
    }

    /* Print the graph */
    void delete_edge(int origin, int destination)
    {
        if (origin > n || destination > n || origin <= 0 || destination <= 0)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destination - 1] = 0;
    }

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
    int nodes, max_edges, edges, origin, destin;

    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    if (edges > (nodes * nodes))
    {
        cout << "Invalid number of edges" << endl;
        return 0;
    }

    AdjacencyMatrix am(nodes);
    for (int i = 0; i < edges; i++)
    {
        cout << "Edges number: " << i + 1 << endl;
        cout << "Enter edge(-1 -1 to exit): " << endl;
        cout << "Enter origin and destination vertices: " << endl;
        cin >> origin >> destin;
        if (origin == 0 || destin == -1)
            break;

        am.add_edge(origin, destin);
    }

    am.display();

    am.delete_edge(1, 2);
    am.delete_edge(2, 2);
    cout << "After deleting two edges" << endl;
    am.display();

    return 0;
}