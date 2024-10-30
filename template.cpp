#include<iostream>
using namespace std;

template<typename T>
T addition(T a,T b){
    return a + b;
}

template<typename K, typename T>
K addition(K a,T b){
    return a + b;
}

int main(){
    cout << "Addition of 2 integer numbers is: " << addition<int>(10, 20) << endl;
    cout << "Addition of 2 double numbers is: " << addition<double>(10.32, 20.43) << endl;
    cout << "Addition of 2 short numbers is: " << addition<short>(6, 8) << endl;
    cout << "The addition of a double and an integer is: " << addition<double,int>(10.32, 65) << endl;

    return 0;
}