#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> orderedMap;
    orderedMap["apple"] = 5;
    orderedMap["banana"] = 6;
    orderedMap["cherry"] = 7;

    for (auto &pair : orderedMap)
        cout << pair.first << " : " << pair.second << endl;

    return 0;
}