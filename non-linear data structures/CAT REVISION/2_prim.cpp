#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int prim(int V, vector<vector<int>> adj[])
    {

        // 1. min-heap pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 2. the visited array prepopulated with zero
        vector<int> vis(V, 0);

        // 3. the sum variable
        int sum;

        // 4. initial config
        pq.push({0, 0});

        // 5. iterate the pq
        while (!pq.empty())
        {
            // the top node and remove it
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            // if it is visited contiye
            if (vis[node] == 1)
                continue;

            // else visit it and enqueue it
            vis[node] == 1;
            sum += wt;

            // go to its adjacents neightbouts
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjWt = it[1];

                // if not visited enqueue them
                if (!vis[adjNode])
                {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return sum;
    }
};