#include<iostream>
using namespace std;

int main(){

    int scores[9] = {52, 78, 75, 68, 88, 63, 75, 90, 78};
    int *sco = scores;
    for (int i = 0; i < 9; i++){
        // cout << scores[i] << ", ";
        // cout << *scores << ", ";
        // cout << &scores << ", ";
        // cout << &sco << ", ";
        // cout << sco << ", ";
        // cout << *(scores + i) << ", ";
        cout << *(sco + i) << ", ";
    }
    cout << endl;

    return 0;
}