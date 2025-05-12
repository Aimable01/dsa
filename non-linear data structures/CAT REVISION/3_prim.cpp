#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> prim(int V, vector<vector<int>> adj[])
    {

        // the initial config
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<int> vis(V, 0);
        vector<pair<int, int>> mst;
        int totalWeight = 0;
        pq.push({0, 0, -1});

        // iterate the pq
        while (!pq.empty())
        {
            auto [w, u, parent_u] = pq.top();
            pq.pop();

            // if visited or not
            if (vis[u] == 1)
                continue;
            vis[u] = 1;
            // add it to mst if not initial
            if (parent_u != -1)
            {
                mst.push_back({u, parent_u});
                totalWeight += w;
            }

            // go to its adjacents
            for (auto it : adj[u])
            {
                int v = it[0];
                int wt = it[1];

                if (!vis[v])
                {
                    pq.push({wt, v, u});
                }
            }
        }

        return mst;
    }
};