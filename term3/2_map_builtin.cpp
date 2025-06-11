#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> uMap;

    uMap["apple"] = 5;
    uMap["banana"] = 6;
    uMap["cherry"] = 7;

    for (auto &pair : uMap)
        cout << pair.first << " : " << pair.second << endl;

    return 0;
}