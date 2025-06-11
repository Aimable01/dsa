#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;

class unorderedMap
{
    vector<pair<string, int>> table[SIZE];

    int hashFunction(string key)
    {
        int hash = 0;
        for (char ch : key)
            hash = (hash * 31 + ch) % SIZE;

        return hash;
    }

public:
    void put(string key, int value)
    {
        int idx = hashFunction(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }

        table[idx].emplace_back(key, value);
    }
};