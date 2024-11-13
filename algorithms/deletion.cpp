#include<iostream>
using namespace std;

int main(){

    int i;
    int scores[] = {52, 78, 75, 68, 88, 63, 75, 90, 78};
    int k = 3; 
    int len = 9; 

    for (i = k; i < len - 1; i++) {
        scores[i] = scores[i + 1];
    }

    len--;

    for (i = 0; i < len; i++) {
        cout << scores[i] << endl;
    }

    return 0;
}
