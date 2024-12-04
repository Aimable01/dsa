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

    return 0;
}