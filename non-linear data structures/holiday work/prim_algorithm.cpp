#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void prim(int V, vector<vector<pii>> &adj)
{
    vector<bool> inMST(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, 0)); // {weight, vertex}

    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        int w = p.first;
        int u = p.second;

        if (inMST[u])
            continue;
        inMST[u] = true;

        cout << "Visited: " << u << " with weight: " << w << endl;

        for (size_t i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (!inMST[v])
            {
                pq.push(make_pair(weight, v));
            }
        }
    }
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

    prim(V, adj);
    return 0;
}
