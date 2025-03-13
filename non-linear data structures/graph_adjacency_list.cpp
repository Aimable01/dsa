#include <iostream>
#include <vector>
using namespace std;

class AdjacencyList
{
private:
    int n;
    vector<pair<int, int>> *adj;

public:
    AdjacencyList(int n)
    {
        this->n = n;
        adj = new vector<pair<int, int>>[n];
    }

    ~AdjacencyList()
    {
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
        adj[origin - 1].push_back({destin - 1, weight});
        adj[destin - 1].push_back({origin - 1, weight}); // Remove this for a directed graph
    }

    /* Display adjacency list */
    void display()
    {
        cout << "Adjacency List:\n";
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " -> ";
            for (auto &edge : adj[i])
            {
                cout << "(" << edge.first + 1 << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes = 5, origin, destin, weight;
    AdjacencyList al(nodes);

    cout << "Enter edges in the format (origin destination weight), enter -1 -1 -1 to stop:\n";
    while (true)
    {
        cin >> origin >> destin >> weight;
        if (origin == -1 || destin == -1 || weight == -1)
            break;
        al.addEdge(origin, destin, weight);
    }

    al.display();
    return 0;
}
