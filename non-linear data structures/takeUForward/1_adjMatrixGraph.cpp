#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // int adj[n + 1][n + 1];
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    // we have m(number of edges rows)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // give edge between u and v
        adj[u][v] = 1; // the intersection marked as 1
        adj[v][u] = 1; // the reverse also marked as 1
    }
    return 0;
}