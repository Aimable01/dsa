#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    // the dfs function
    void dfs(int node, vector<int> adj[], vector<int> vis, vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);

        // traverse to all its neighbouts
        for (auto it : adj[node])
        {
            if (!vis[it]) // if the node is not visited
            {
                dfs(it, adj, vis, ls); // recursive call the dfs
            }
        }
    }

public:
    // function to return the dfs of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);    // the array of visited
        int start = 0;            // the starting index is zero
        vector<int> ls;           // the list to store the dfs
        dfs(start, adj, vis, ls); // call the dfs
        return ls;
    }
};