#include <iostream>
using namespace std;

int main()
{
    float PI = 3.14;
    float *PIptr;
    float r = 5, A;
    float x;
    PIptr = &PI; // ptr to pi
    x = *PIptr;  // x is now pi (3.14)
    A = r * r * x;
    cout << "The area of the cirlce is " << A << endl;

    return 0;
}
