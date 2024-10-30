#include <iostream>
using namespace std;
#define PI 3.14

// to find area and circumference
double area(int radius)
{
    return radius * radius * PI;
}

int main()
{

    int k = 181;
    int a = k >> 1;
    int b = k >> 2;
    int c = k << 1;
    int d = k << 2;

    cout << "a-->" << a << " b-->" << b << " c-->" << c << " d-->" << d << endl;

    // constants
    const double pi = 3.14;
    cout << "The global PI: " << PI << " and the local pi: " << pi << endl;

    // find the area
    int radius;
    cout << "Enter the raduis of the circle: ";
    cin >> radius;
    cout << "The area is: " << area(radius);

    return 0;
}