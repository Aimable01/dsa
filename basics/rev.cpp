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
    cin.ignore();
    cout << "Your name is: " << name << " and you are: " << age << endl;

    // interest calculator
    string fullname;
    double initialAmount;
    float interestRate;
    int years;
    double totalAmount;

    cout << "Enter your fullname: ";
    getline(cin, fullname);
    cout << "Enter the initial amount: ";
    cin >> initialAmount;
    cout << "Enter the interest rate (eg: 2.34): ";
    cin >> interestRate;
    cout << "Enter the number of years: ";
    cin >> years;

    totalAmount = initialAmount * interestRate * years;
    cout << fullname << " ,the total amount is: " << totalAmount << endl;

    return 0;
}
