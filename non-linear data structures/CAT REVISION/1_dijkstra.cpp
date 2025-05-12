#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // 1. define a min-heap priority quueue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 2. define the distance array
        vector<int> dist(V);

        // 3. mark the source node and distance zero and push it
        dist[S] = 0;
        pq.push({0, S});

        // 4. iterate the priority queue
        while (!pq.empty())
        {
            // 5. get the top distance, node and pop it
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // 6. go to it's adjacents
            for (auto it : adj[node])
            {

                // 7. get the distance
                int edgeWeight = it[0];
                int adjNode = it[1];

                // 8. compare the distance
                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // 9. return the distance vector
        return dist;
    }
};