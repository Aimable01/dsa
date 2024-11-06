#include<iostream>
using namespace std;

namespace myCustomNameSpace{

    int amount = 2000;

    int duplicateAmount(){
        return amount * 2;
    }
}

int amount = 5000;

int main(){

    int amount = 3000;

    cout << "The local amount is: " << amount << endl;
    cout << "The global amount is: " << ::amount << endl;
    cout << "The amount from my custom namespace is: " << myCustomNameSpace::amount << endl;
    cout << "The amount duplicated is: " << myCustomNameSpace::duplicateAmount() << endl;

    return 0;
}