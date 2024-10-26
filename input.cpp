#include<iostream>
using namespace std;

int main(){

    string name;
    int y1, y2, y3, y4;

    cout << "Enter your name: ";
    // cin >> name; // used to get a single word
    getline(cin, name); // uset to get a line
    cout << "The name input is: " << name << endl;

    cout << "Enter four memorable years: ";
    cin >> y1 >> y2 >> y3 >> y4;
    cout << "Your had good success in: " << y1 << ", " << y2 << ", " << y3 << ", "<<y4;

    return 0;
}