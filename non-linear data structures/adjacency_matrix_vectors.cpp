#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /* `n` is the number of vertices and `e` is the number of vertices*/
    int n, e;
    cin >> n >> e;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 1; i < e; i++)
    {
        /* `fv` first vertex and `sv` second vertex */
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    /* display the elements */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}