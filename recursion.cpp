#include<iostream>
using namespace std;

// the factorial of a number
int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    int smallAnswer = fact(n - 1);

    return n * smallAnswer;
}

// the sum of digits of a number
int sumDigits(int n){
    if(n < 10){
        return n;
    }

    int smallAnswer = sumDigits(n / 10);

    return n % 10 + smallAnswer;
}

int main(){
    int n = 5;
    int answer = fact(n);
    cout << "The factorial of " << n << " is: " << answer << endl;

    int num = 345;
    int sum = sumDigits(num);
    cout << "The sum of digits of " << num << " is: " << sum << endl;

    return 0;
