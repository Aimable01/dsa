#include<iostream>
using namespace std;

int main(){

    int a[3][4] = {
        10, 11, 12, 13,
        14, 15, 16, 17,
        18, 19, 20, 21,
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4;j++){
            cout << "A" << a[i][j] << " ";
        }
        cout << endl;
    }

    // with omitted size
    cout << "-------------OMITTED SIZE--------------" << endl;

    int b[][4] = {
        10, 11, 12, 13,
        14, 15, 16, 17,
        18, 19, 20, 21,
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4;j++){
            cout << "A" << b[i][j] << " ";
        }
        cout << endl;
    }
}