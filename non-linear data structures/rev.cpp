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
        /* Initializing an empty matrix */
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
            cout << "Invalid edge!\n";
            return;
        }

        adj[origin - 1][destin - 1] = 1;
    }

    /* Print the graph */
    void deleteEdge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            return;
        }

        adj[origin - 1][destin - 1] = 0;
    }

    void display()
    {
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
    int nodes, max_edges, origin, destin;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout << "Edge number: " << ++i << endl;
        cout << "Enter edge (-1 -1 to exit): ";
        cin >> origin >> destin;
        if ((origin == -1) && (destin == -1))
        {
            break;
        }
        am.addEdge(origin, destin);
    }

    am.display();

    /*
    AdjacencyMatrix g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.display();
    g.deleteEdge(1, 2);
    g.display();
    return 0;
    */
}
