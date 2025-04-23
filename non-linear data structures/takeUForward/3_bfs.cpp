#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // function to return the BFS traversal of a given graph
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0); // the array vector of visited nodes
        vis[0] = 1;            // mark the first one visited
        queue<int> q;          // the queue of the nodes
        q.push(0);             // add the first node

        vector<int> bfs; // the output vector array

        // always remove something while the queue is not empty
        while (!q.empty())
        {
            int node = q.front();
            q.pop();             // remove the node from the queue
            bfs.push_back(node); // put it in output array

            // the adjacent nodes to the node
            for (auto it : adj[node])
            {
                if (!vis[it]) // if they are not visisted
                {
                    vis[it] = 1; // visit them
                    q.push(it);  // put them in the queue
                }
            }
        }

        return bfs;
    }
};