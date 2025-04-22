#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Required for INT_MAX
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V, vector<vector<pii>> &adj, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, src)); // {distance, vertex}

    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        int d = p.first;
        int u = p.second;

        for (size_t i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
}

int main()
{
    int V = 6;
    vector<vector<pii>> adj(V);

    adj[0] = {{1, 4}, {5, 2}};
    adj[1] = {{0, 4}, {2, 6}, {5, 5}};
    adj[2] = {{1, 6}, {3, 3}};
    adj[3] = {{2, 3}, {4, 2}};
    adj[4] = {{3, 2}, {5, 4}};
    adj[5] = {{0, 2}, {1, 5}, {4, 4}};

    dijkstra(V, adj, 0);
    return 0;
}
