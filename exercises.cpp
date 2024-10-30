#include <iostream>
using namespace std;

int sumOfDigits(int number){
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int addition(int a, int b){
    return a + b;
}

double addition(double a, double b){
    return a + b;
}

float addition(float a, float b){
    return a + b;
}

short addition(short a, short b){
    return a + b;
}

long addition(long a, long b){
    return a + b;
}

double addition(double a, int b){
    return a + b;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The sum of its digits is: " << sumOfDigits(n) << endl;

    int a, b;
    cout << "Enter the two numbers: ";
    cin >> a >> b;
    cout << "The sum is: " << addition(a, b) << endl;

    int doubleA, doubleB;
    cout << "Enter the two doubles: ";
    cin >> doubleA >> doubleB;
    cout << "The sum of the doubles is: " << addition(doubleA, doubleB) << endl;

    return 0;
}