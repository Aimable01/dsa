#include<iostream>
using namespace std;

// the factorial of a number
int fact(int n){

    // base case
    if(n == 0 || n == 1){
        return 1;
    }

    // recursive case
    int smallAnswer = fact(n - 1);

    return n * smallAnswer;
}

// the sum of digits of a number
int sumDigits(int n){

    // base case
    if(n < 10){
        return n;
    }

    // recursive case
    int smallAnswer = sumDigits(n / 10);

    return n % 10 + smallAnswer;
}

// the power of a number
int power(int x, int n) {

    // base case
    if(n == 0){
        return 1;
    }

    // recursive case
    int smallAnswer = power(x, n - 1);

    return x * smallAnswer;
}

// fibonnacci
int fibbonacci(int n){

    // base case
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    // recursive case
    int smallOutput1 = fibbonacci(n - 1);
    int smallOutput2 = fibbonacci(n - 2);

    return smallOutput1 + smallOutput2;
}

int main(){
    int n = 5;
    int answer = fact(n);
    cout << "The factorial of " << n << " is: " << answer << endl;

    int num = 345;
    int sum = sumDigits(num);
    cout << "The sum of digits of " << num << " is: " << sum << endl;

    int numBase = 2, numPower = 5;
    int powerAnswer = power(numBase, numPower);
    cout << "The power of " << numBase << " is: " << powerAnswer << endl;

    int fibNum = 6;
    int fibAnswer = fibbonacci(fibNum);
    cout << "The fibbonacci number at " << fibNum << " is: " << fibAnswer << endl;

    return 0;
}