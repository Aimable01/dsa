#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution
{
private:
    // helper fn to find parents
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] != node)
        {
            return findParent(parent, parent[node]);
        }
        return parent[node];
    }

    // helper fn to union the sets
    void unionSets(vector<int> &parent, vector<int> &rank, int u, int v)
    {
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        // union by rank
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

public:
    vector<pair<int, int>> kruskal(int V, vector<vector<int>> adj[])
    {
        // 1. extract all edges from the adjacency list
        vector<tuple<int, int, int>> edges;
        for (int u = 0; u < V; u++)
        {
            for (auto &edge : adj[u])
            {
                int v = edge[0];
                int wt = edge[1];
                // To avoid duplicate edges (since graph is undirected)
                if (u < v)
                {
                    edges.emplace_back(wt, u, v);
                }
            }
        }

        // Step 2: Sort edges by weight
        sort(edges.begin(), edges.end());

        // Union-Find data structures
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        vector<pair<int, int>> mst;
        int totalWeight = 0;

        // Step 3: Process each edge in sorted order
        for (auto &[wt, u, v] : edges)
        {
            int rootU = findParent(parent, u);
            int rootV = findParent(parent, v);

            // If including this edge doesn't cause a cycle
            if (rootU != rootV)
            {
                mst.emplace_back(u, v);
                totalWeight += wt;
                unionSets(parent, rank, rootU, rootV);

                // Early exit if we've included enough edges
                if (mst.size() == V - 1)
                    break;
            }
        }

        return mst;
    }
};