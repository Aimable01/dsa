#include<iostream>
using namespace std;

template<typename T>
T addition(T a,T b){
    return a + b;
}

int main(){
    cout << "Addition of 2 numbers" << addition(10, 20) << endl;

    return 0;
}