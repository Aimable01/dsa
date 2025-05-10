#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // function to find sum of weights of edges of the MST
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // the min-heap priority queue (weight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // the visited array
        vector<int> vis(V, 0);

        // {wt, node}
        pq.push({0, 0});

        // the weight sum
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (!vis[node] == 1)
                continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;

            // now to its adjacent nodes
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};