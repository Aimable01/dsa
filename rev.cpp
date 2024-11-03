#include<iostream>
#include<string>
using namespace std;

int main(){

    string name;
    int age;

    // personal details display
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your name is: " << name << " and you are: " << age << endl;

    return 0;
}