#include<iostream>
using namespace std;

namespace Operations{
    float fn1(float a, float b){
        return a + b;
    }

    float fn2(float a, float b){
        return a * b;
    }
}

float v1, v2;

int main(){

    cout << "Enter the value for v1: ";
    cin >> v1;
    cout << "Enter the value for v2: ";
    cin >> v2;

    cout << "Result 1: " << Operations::fn1(v1, v2) << endl;
    cout << "Result 2: " << Operations::fn2(v1, v2) << endl;
    cout << "Result 3: " << (Operations::fn2(v1,v2) + Operations::fn2(v1,v2)) << endl;

    return 0;
}