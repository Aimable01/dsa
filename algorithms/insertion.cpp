#include<iostream>
using namespace std;

int main(){

    int i;
    int j;
    int scores[10] = {52, 78, 75, 68, 88, 63, 75, 90, 78};
    int item = 10, k = 3, len = 9;
    j = len - 1;

    while (j >= k) {
        scores[j + 1] = scores[j];
        j = j - 1;
    }

    scores[k] = item;
    len++;

    for (i = 0; i < len; i++) {
        cout << scores[i] << endl;
    }

    return 0;
}
