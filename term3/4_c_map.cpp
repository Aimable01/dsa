#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class HashTable
{
private:
    // number of buckets
    static const int HASH_GROUPS = 10;
    vector<list<pair<int, string>>> table;

public:
    HashTable()
    {
        table.resize(HASH_GROUPS);
    }

    int hashFunction(int key)
    {
        return key % HASH_GROUPS;
    }

    void insert(int key, const string &value)
    {
        int hashValue = hashFunction(key);
        auto &cell = table[hashValue];
        for (auto &pair : cell)
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }

        cell.emplace_back(key, value);
    }

    string serach(int key)
    {
        int hashValue = hashFunction(key);
        auto &cell = table[hashValue];
        for (const auto &pair : cell)
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return "Key not found";
    }

    void display()
    {
        for (int i = 0; i < HASH_GROUPS; ++i)
        {
            cout << "Bucket " << i << ": ";
            for (const auto &pair : table[i])
            {
                cout << "[" << pair.first << ": " << pair.second << "]";
            }
            cout << "\n";
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert(905, "John");
    ht.insert(201, "Jane");
    ht.insert(332, "Tom");
    ht.insert(32, "Ange");
    ht.insert(124, "Mike");
    ht.insert(154, "Michael");
    ht.insert(127, "Chael");
    ht.insert(107, "Alice");

    ht.display();

    return 0;
}