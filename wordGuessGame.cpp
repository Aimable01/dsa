#include<iostream>
using namespace std;

// get user choice
int getChoice(){

    int choice;

    cout << "Welcome to the word guessing game." << endl;
    cout << "We have different categories." << endl;
    cout << "1 - names of animals" << endl;
    cout << "2 - names of teams" << endl;
    cout << "3 - names of districts" << endl;
    cout << "4 - names of books" << endl;
    cout << "5 - names of films" << endl;
    cout << "Enter the number corresponding to your desired category: ";
    cin >> choice;

    return choice;
}

int main(){

    int choice = getChoice();
    cout << "You choose: " << choice;


    return 0;
}