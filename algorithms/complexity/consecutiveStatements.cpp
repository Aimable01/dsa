#include <iostream>
using namespace std;

int fun7(int n) {
    int i, j, k, m = 0;

    // First pair of nested loops
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m += 1;
        }
    }

    // Second pair of nested loops
    for (i = 0; i < n; i++) { 
        for (k = 0; k < n; k++) {
            m += 1;
        }
    }

    return m;
}

// Testing Code
int main() {
    std::cout << "N = 100, Number of instructions O(n^2) :: " << fun7(100);
    return 0;
}
