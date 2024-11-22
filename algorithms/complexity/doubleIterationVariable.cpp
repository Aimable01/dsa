#include <iostream>
using namespace std;

int fun6(int n) {
    int i = 1, m = 0;
    while (i < n) {
        m += 1;
        i = i * 2;  // Double i in each iteration
    }
    return m;
}

// Testing Code
int main() {
    printf("N = 100, Number of instructions O(log(n)) :: %d \n", fun6(100));
    return 0;
}
