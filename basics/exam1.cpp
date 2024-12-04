#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    // output formatting
    // 1. endl
    cout << "Hello, World!" << endl;

    cout << "----------------------------------------------------" << endl;

    // 2. setw()
    int num = 50;
    cout << "Before setting the width:\n"
         << num << endl;
    cout << "After setting the width:\n"
         << setw(20) << num << endl;

    cout << "----------------------------------------------------" << endl;

    // 3. setprecision()
    cout << setprecision(2) << fixed << 1234.56789 << endl;
    cout << setprecision << 3 << scientific << 1234.56789 << endl;

    cout << "----------------------------------------------------" << endl;

    // 4. base output
    int value = 100;
    cout << "Decimal: " << dec << value << endl;
    cout << "Octal: " << oct << value << endl;
    cout << "Hexadecimal: " << hex << value << endl;

    cout << "----------------------------------------------------" << endl;

    // 4. maths operators
    cout << "Power: " << pow(2, 3) << endl;
    cout << "Hypotenuse: " << sqrt(pow(2, 3) + pow(3, 2)) << endl;

    cout << "----------------------------------------------------" << endl;

    // print all pairs that satisfy pythagoras' theorem
    int count = 0;

    for (int a = 2; a < 100; ++a) {
        for (int b = a; b < 100; ++b) {
            double c = std::sqrt(a * a + b * b);
            if (c == static_cast<int>(c)) {
                std::cout << "(" << a << ", " << b << ")\n";
                ++count;
            }
        }
    }

    std::cout << "Total number of pairs: " << count << std::endl;


    return 0;
}