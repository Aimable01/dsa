#include <iostream>
#include <vector>
using namespace std;
void printDFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    // SV as a Starting vertex
    cout << sv << endl;
    visited[sv] = true;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            printDFS(v, i, visited);
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    cout << "Reading" << n << "vertices numbered from 0 to " << n - 1 << endl;
    cout << "Enter first Vertex and second vertex" << endl;
    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    cout << "DFS " << endl;
    vector<bool> visited(n, false);
    printDFS(matrix, 0, visited);
    return 0;
}
