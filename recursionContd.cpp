#include<iostream>
using namespace std;

void multiples(int n){

    // base case
    if(n < 10){
        return;
    }

    // recursive step
    int quotient = n / 10;
    int multiple = quotient * 10;
    multiples(n - 10);
    
    cout << multiple << " ";
}

int main(){
    multiples(59);
    return 0;
}