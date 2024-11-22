#include <iostream>
using namespace std;

int fun5(int n) {
    int i, j, m = 0;
    for (i = 1; i <= n; i *= 2) {  // i doubles with each iteration
        for (j = 0; j <= i; j++) {
            m += 1;
        }
    }
    return m;
}

// Testing Code
int main() {
    std::cout << "N = 100, Number of instructions O(log n) :: " << fun5(100); 
    return 0;
}
