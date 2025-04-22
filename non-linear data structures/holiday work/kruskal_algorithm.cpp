#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

int find(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u], parent);
}

void kruskal(int v, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
        parent[i] = i;

    vector<Edge> result;
    for (Edge &e : edges)
    {
        int set_u = find(e.u, parent);
        int set_v = find(e.v, parent);
        if (set_u != set_v)
        {
            result.push_back(e);
            parent[set_u] = set_v;
        }
    }

    for (Edge &e : result)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
}

int main()
{
    int v = 6;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 5, 2},
        {1, 2, 6},
        {1, 5, 5},
        {2, 3, 3},
        {3, 4, 2},
        {4, 5, 4}};

    kruskal(v, edges);
    return 0;
}