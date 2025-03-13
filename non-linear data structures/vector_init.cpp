#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /**
     * Method 1
     * Initializer list
     */
    vector<int> vector1 = {1, 2, 3, 4, 5};

    /**
     * Method 2
     * Uniform initialization
     */
    vector<int> vector2{6, 7, 8, 9, 10};

    /**
     * Method 3
     * Constructor initialization
     */
    vector<int> vector3{5, 12};

    cout << "Vector from method 1 = ";
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }

    cout << "\nVector from method 2 = ";
    for (int i = 0; i < vector2.size(); i++)
    {
        cout << vector2[i] << " ";
    }

    cout << "\nVector from method 3 = ";
    for (int i = 0; i < vector3.size(); i++)
    {
        cout << vector3[i] << " ";
    }

    return 0;
}