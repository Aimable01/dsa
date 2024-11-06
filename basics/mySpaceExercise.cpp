#include<iostream>

namespace userDefined{

    int insideNamespace = 20;

    int cout(){
        return insideNamespace;
    }
}

int myGlobal = 30;

int cout(){
    return myGlobal * myGlobal;
}

int main(){

    int cout = 40;

    std::cout << "The local variable cout in main is: " << cout << std::endl;
    std::cout << "The variable in userDefined namespace is: " << userDefined::insideNamespace << std::endl;
    std::cout << "The output of cout() in userDefined is: " << userDefined::cout() << std::endl;
    std::cout << "The value of myGlobal is: " << ::myGlobal << std::endl;
    std::cout << "The output of global cout() is: " << ::cout() << std::endl;
}