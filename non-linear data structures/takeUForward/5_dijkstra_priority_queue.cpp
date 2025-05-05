#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all vertices
    // from the source vertex S
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // 1. create a min-heap priority queue of {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 2. create a distance array
        vector<int> dist(V);

        // 3. mark all the distances infinite
        for (int i = 0; i < V; i++)
            dist[i] = 1e9;

        // 4. the initial config
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;   // get the distance
            int node = pq.top().second; // get the node
            pq.pop();                   // remove the top from the priority queue

            // travel to adjacent nodes
            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if ((dis + edgeWeight) < dist[adjNode]) // you got a better distance
                {
                    dist[adjNode] = dis + edgeWeight;  // update the distance
                    pq.push({dist[adjNode], adjNode}); // push it into the queue cz we got a better distance
                }
            }
        }

        return dist;
    }
};