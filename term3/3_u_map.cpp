#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // creating a map
    unordered_map<string, int> myStock;

    // inserting a new key-value pair
    myStock["apple"] = 100;
    myStock["banana"] = 200;
    myStock["cherry"] = 300;
    myStock["pineapple"] = 500;
    myStock["mango"] = 600;

    // retrieving the value associated with a key
    int qty = myStock["banana"];
    cout << "Value for key 'banana': " << qty << endl;

    // updating the value associated with a key
    myStock["banana"] = 250;
    qty = myStock["banana"];
    cout << "updated value for key 'banana': " << qty << endl;

    // removing a key-value pair
    cout << "Key-value pairs in the map: " << endl;
    for (const auto &pair : myStock)
    {
        cout << pair.first << " , " << pair.second << endl;
    }

    return 0;
}